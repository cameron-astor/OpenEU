#include "LoadingTask.h"

namespace BW {

    LoadingTask::LoadingTask(AssetWarehouse& assets):
        m_Assets(assets),
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
        m_Assets.loadAllTextures();
        m_Assets.loadAllFonts();
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
