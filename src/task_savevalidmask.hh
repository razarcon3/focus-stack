// Saves image valid-region masks as PNG files

#pragma once
#include "worker.hh"

namespace focusstack {

class Task_SaveValidMask: public Task
{
public:
  Task_SaveValidMask(std::string filename, std::shared_ptr<ImgTask> input, bool nocrop = false);

private:
  void task() override;

  std::shared_ptr<ImgTask> m_input;
  bool m_nocrop;
};

}