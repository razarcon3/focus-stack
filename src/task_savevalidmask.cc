#include "task_savevalidmask.hh"
#include <opencv2/imgcodecs.hpp>

using namespace focusstack;

Task_SaveValidMask::Task_SaveValidMask(std::string filename, std::shared_ptr<ImgTask> input, bool nocrop):
  m_input(input), m_nocrop(nocrop)
{
  m_filename = filename;
  m_name = "Save valid mask " + filename;
  m_depends_on.push_back(input);
}

void Task_SaveValidMask::task()
{
  cv::Mat mask = m_nocrop ? m_input->valid_mask() : m_input->valid_mask_cropped();
  cv::imwrite(m_filename, mask);
  m_input.reset();
}