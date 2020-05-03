#ifndef LOADINGTASK_H
#define LOADINGTASK_H

#include <thread>
#include <Managers/TextureManager.h>
#include <Managers/FontManager.h>

namespace BW {

    class LoadingTask
    {
        public:
            LoadingTask(TextureManager* tm, FontManager* fm);
            virtual ~LoadingTask();

            void run();

        private:
            void load();
            TextureManager *m_Textures;
            FontManager *m_Fonts;

    };

}

#endif // LOADINGTASK_H
