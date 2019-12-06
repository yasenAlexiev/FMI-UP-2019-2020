#include <iostream>

#define MAX_SIZE (1<<9)
#define CAPACITY (1<<6)

unsigned short countLD = 0;
unsigned short dmx[MAX_SIZE];
unsigned short startIndexes[CAPACITY];
unsigned short serialNumbers[CAPACITY];
unsigned short channelsForLD[CAPACITY];

const char empty = '_';
const char good = 'o';
const char duplicate = '+';
const char conflict = 'x';

void printSchema() {
    for(int i = 0; i < MAX_SIZE; ++i) {
        switch(dmx[i]) {
            case 0:
                std::cout << empty;
                break;
            case 1:
                std::cout << good;
                break;
            case 2:
                std::cout << conflict;
                break;
            case 3:
                std::cout << duplicate;
                break;
            default:
                std::cout << ' ';
                break;
        }
        if((i+1) % 50 == 0) {
            std::cout << std::endl;
        }
    }
}

void clearTable() {
    for(int i = 0; i < MAX_SIZE; ++i) {
        dmx[i] = 0;
    }
}

bool hasLDOnTheSamePosition(const unsigned short index) {
    for(short i = 0; i < CAPACITY; ++i) {
        if(i != 0 && i != index && startIndexes[index] == startIndexes[i] && channelsForLD[index] == channelsForLD[i] ) {
            return true;
        }
    }
    return false;
}

void setDuplicate(const unsigned short index) {
    for(int j = startIndexes[index]; j < startIndexes[index] + channelsForLD[index]; ++j) {
        dmx[j] = 3;
    }
}
void updateDMXTable() {
    clearTable();
    for(unsigned short i = 0; i < CAPACITY; ++i) {
        if(serialNumbers[i] != 0) {
            if( hasLDOnTheSamePosition(i) > 0) {
                setDuplicate(i);
            } else {
                for(int j = startIndexes[i]; j < startIndexes[i] + channelsForLD[i]; ++j) {
                    if(dmx[j] == 3) {
                        continue;
                    } else {
                        ++dmx[j];
                    }
                }
            }
        }
    }
}

bool isValidSerialNumber(const unsigned short serialNumber) {
    unsigned short mask = (1 << 15);
    unsigned short countBits = 0;
    while(mask > 0) {
        if(serialNumber & mask ) {
            countBits++;
        }
        mask >>= 1;
    }
    return (serialNumber % countBits) == 0;
}

bool isValidPosition(const unsigned short startingIndex, const unsigned short numberOfChannels) {
    return startingIndex < (MAX_SIZE - numberOfChannels - 1);
}

bool hasBeenAddedBefore(const unsigned short serialNumber) {
    for(int i = 0; i < CAPACITY; ++i) {
        if(serialNumber == serialNumbers[i]) {
            return true;
        }
    }
    return false;
}

bool addLightingDevice(const unsigned short serialNumber, const unsigned short numberOfChannels, const unsigned short startingIndex) {
    bool success = false;
    if(isValidPosition(startingIndex, numberOfChannels) && isValidSerialNumber(serialNumber)
            && !hasBeenAddedBefore(serialNumber)) {
        for(int i = 0; i < CAPACITY && !success; ++i) {
            if(serialNumbers[i] == 0) {

                serialNumbers[i] = serialNumber;
                startIndexes[i] = startingIndex;
                channelsForLD[i] = numberOfChannels;

                success = true;
                countLD++;
                updateDMXTable();
            }
        }
    }
    return success;
}

bool removeLightingDeviceByIndex(const unsigned short index) {

    serialNumbers[index] = 0;
    startIndexes[index] = 0;
    channelsForLD[index] = 0;

    return true;
}


bool removeLightingDevice(const unsigned short serialNumber) {
    bool success = false;

    for(int i = 0; i < CAPACITY && !success; ++i) {
        if(serialNumbers[i] == serialNumber) {
            removeLightingDeviceByIndex(i);
            success = true;
            countLD--;
            updateDMXTable();
        }
    }

    return success;
}

bool moveLightingDevice(const unsigned short serialNumber, const unsigned short newStartingIndex) {
    bool success = false;
    for(unsigned short i = 0; i < CAPACITY && !success; ++i) {
        if(serialNumbers[i] == serialNumber) {
            if(isValidPosition(newStartingIndex, channelsForLD[i])) {
                const unsigned short channels = channelsForLD[i];
                removeLightingDeviceByIndex(i);
                success = addLightingDevice(serialNumber, channels, newStartingIndex);
                updateDMXTable();
            }
        }
    }
    return success;
}


int main() {
    char command;
    unsigned short serialNumber;
    unsigned short numberOfChannels;
    unsigned short startingIndex;
    while(true) {
        std::cout << "\nEnter new command: ";
        std::cin >> command;

        switch(command) {
            case 'a':
                std::cin >> serialNumber >> numberOfChannels >> startingIndex;
                if(countLD == CAPACITY-1) {
                    std::cout << "You reach a limit of " << CAPACITY << " lighting devices in DMX Patching system!"
                              << std::endl;
                } else if(!addLightingDevice(serialNumber, numberOfChannels, startingIndex)) {
                    std::cout << "Adding lighting device is failing!" << std::endl;
                }
                break;
            case 'r':
                std::cin >> serialNumber;
                if(!removeLightingDevice(serialNumber)) {
                    std::cout << "Removing lighting device is failing" << std::endl;
                }
                break;
            case 'm':
                std::cin >> serialNumber >> startingIndex;
                if(!moveLightingDevice(serialNumber, startingIndex)) {
                    std::cout << "Moving lighting device is failing" << std::endl;
                }
                break;
            case 'p':
                printSchema();
                break;
            case 'e':
                return 1;
            default:
                std::cout << "Invalid command. Please try again" << std::endl;
                break;
        }

    }

    return 0;
}