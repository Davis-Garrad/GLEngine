#pragma once

/*
This class handles multiple types of files and data:
- JSON
- ASCII Text
- Binary Data (Datatypes)
*/

namespace GLEngine {

    struct JSON_Data {

    };

    enum class FileTypeFlags {
        BINARY,
        TEXT,
        JSON
    };

    template <typename T>

    class DataHandler
    {
        public:
            void readDataFromFile(std::string& fileName, T* data, FileTypeFlags& flags);
            void writeDataToFile(std::string& fileName, T* data, FileTypeFlags& flags);

            void readDataFromJSON(std::string& fileName, JSON_Data* data);

        protected:

        private:
    };

}
