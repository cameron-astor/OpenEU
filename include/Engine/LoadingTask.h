#ifndef LOADINGTASK_H
#define LOADINGTASK_H

#include <thread>
#include <Managers/TextureManager.h>
#include <Managers/FontManager.h>

namespace BW {

    class LoadingTask
    {
        public:
            LoadingTask(TextureManager& tm, FontManager& fm);
            virtual ~LoadingTask();

            // execute the loading task
            void run();
            bool isFinished();
            void joinThread();

        private:
            void load();
            TextureManager& m_Textures;
            FontManager& m_Fonts;

        private:
            bool m_Finished;
            std::thread m_Task;

    };

}

#endif // LOADINGTASK_H
