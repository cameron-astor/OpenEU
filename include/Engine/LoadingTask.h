#ifndef LOADINGTASK_H
#define LOADINGTASK_H

#include <thread>
#include <Managers/AssetWarehouse.h>

namespace BW {

    class LoadingTask
    {
        public:
            LoadingTask(AssetWarehouse& assets);
            virtual ~LoadingTask();

            // execute the loading task
            void run();
            bool isFinished();
            void joinThread();

        private:
            void load();
            AssetWarehouse& m_Assets;

        private:
            bool m_Finished;
            std::thread m_Task;

    };

}

#endif // LOADINGTASK_H
