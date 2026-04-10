// Intersects valid-region masks from multiple aligned images.

#pragma once
#include "worker.hh"

namespace focusstack {

class Task_MergeValidMask: public ImgTask
{
public:
  Task_MergeValidMask(std::shared_ptr<ImgTask> previous, std::shared_ptr<ImgTask> current);

private:
  void task() override;

  std::shared_ptr<ImgTask> m_previous;
  std::shared_ptr<ImgTask> m_current;
};

}