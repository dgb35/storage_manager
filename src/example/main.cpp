#include "example/constants.hpp"
#include "example/sel_event_record.hpp"
#include "storage_manager.hpp"

#include <iostream>

int main()
{
    StorageManager<SelEventRecord> manager(path / fileName);
    std::cout << "Storage path: " << manager.path() << std::endl;

    manager.clear_storage();

    // how many entries will be written
    constexpr size_t count = 5;

    const SelEventRecord record{1, 2, 3, 4, 5, 6, 7, 8, {9, 10, 11}};

    // writing data
    for (int i = 0; i < count; ++i)
        manager.add_record(record);

    // loading data
    auto entries = manager.load_records();

    std::cout << "Number of entries: " << entries.size() << std::endl
              << std::endl;
    std::cout << "SEL records" << std::endl << std::endl;
    for (const auto& entry : entries)
    {
        std::cout << "recordID: " << entry.recordID << std::endl;
        std::cout << "recordType: " << (int)entry.recordType << std::endl;
        std::cout << "timeStamp: " << entry.timeStamp << std::endl;
        std::cout << "generatorID: " << entry.generatorID << std::endl;
        std::cout << "eventMsgRevision: " << (int)entry.eventMsgRevision
                  << std::endl;
        std::cout << "sensorType: " << (int)entry.sensorType << std::endl;
        std::cout << "sensorNum: " << (int)entry.sensorNum << std::endl;
        std::cout << "eventType: " << (int)entry.eventType << std::endl;
        std::cout << "eventData[0]: " << (int)entry.eventData[0] << std::endl;
        std::cout << "eventData[1]: " << (int)entry.eventData[1] << std::endl;
        std::cout << "eventData[2]: " << (int)entry.eventData[2] << std::endl
                  << std::endl;
    }

    std::cout << "SEL entry size: " << 16 << std::endl;
    std::cout << "Storage size: " << manager.storage_size() << std::endl;
    return 0;
}
