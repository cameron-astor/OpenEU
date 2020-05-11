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
        m_Task = std::thread( [this] { this->load(); } );
    }

    void LoadingTask::load()
    {
        m_Textures.loadAll();
        m_Fonts.loadAll();
        m_Finished = true;
    }

    bool LoadingTask::isFinished()
    {
        return m_Finished;
    }

    void LoadingTask::joinThread()
    {
        m_Task.join();
    }

}
