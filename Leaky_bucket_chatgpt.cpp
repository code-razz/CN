#include <iostream>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

class LeakyBucket {
private:
    int bucketSize;
    int outputRate;
    int currentSize;

public:
    LeakyBucket(int bucketSize, int outputRate)
        : bucketSize(bucketSize), outputRate(outputRate), currentSize(0) {}

    void addPacket(int packetSize) {
        if (packetSize + currentSize > bucketSize) {
            cout << "Packet of size " << packetSize << " dropped (bucket overflow)" << endl;
        } else {
            currentSize += packetSize;
            cout << "Packet of size " << packetSize << " added to the bucket" << endl;
        }
    }

    void leak() {
        if (currentSize > 0) {
            int leaked = min(outputRate, currentSize);
            currentSize -= leaked;
            cout << "Leaked " << leaked << " bytes from the bucket" << endl;
        } else {
            cout << "Bucket is empty, nothing to leak" << endl;
        }
    }

    int getCurrentSize() const {
        return currentSize;
    }
};

void simulateLeakyBucket(LeakyBucket &bucket, const queue<int> &packets, int interval) {
    auto packetsCopy = packets;

    while (!packetsCopy.empty() || bucket.getCurrentSize() > 0) {
        if (!packetsCopy.empty()) {
            int packetSize = packetsCopy.front();
            packetsCopy.pop();
            bucket.addPacket(packetSize);
        }

        bucket.leak();

        this_thread::sleep_for(chrono::seconds(interval));
    }
}

int main() {
    int bucketSize = 10; // in bytes
    int outputRate = 3;  // in bytes per second

    LeakyBucket bucket(bucketSize, outputRate);

    queue<int> packets;
    packets.push(5);
    packets.push(7);
    packets.push(3);
    packets.push(1);
    packets.push(2);

    int interval = 1; // seconds

    simulateLeakyBucket(bucket, packets, interval);

    return 0;
}
