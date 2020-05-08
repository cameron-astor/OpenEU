#include "LoadingTask.h"

namespace BW {

    LoadingTask::LoadingTask(TextureManager& tm, FontManager& fm):
        m_Textures(tm), m_Fonts(fm),
        m_Finished(false)
    {
        //ctor
    }

    LoadingTask::~LoadingTask()
    {
        //dtor
    }

    void LoadingTask::run()
    {
        std::thread load ( [this] { this->load(); } );
        load.join();
        m_Finished = true;
    }

    void LoadingTask::load()
    {
        m_Textures.load("assets/gfx/textures/main_menu/frontend_backdrop.png");
        m_Textures.load("assets/gfx/textures/main_menu/menu_button.png");
        m_Fonts.load("assets/gfx/fonts/Px437_IBM_BIOS.ttf");
    }

    bool LoadingTask::isFinished()
    {
        return m_Finished;
    }


}
