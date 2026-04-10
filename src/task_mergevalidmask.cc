#include "task_mergevalidmask.hh"

using namespace focusstack;

Task_MergeValidMask::Task_MergeValidMask(std::shared_ptr<ImgTask> previous, std::shared_ptr<ImgTask> current):
  m_previous(previous), m_current(current)
{
  m_filename = "validmask.png";
  m_name = "Merge valid masks";
  m_depends_on.push_back(previous);
  m_depends_on.push_back(current);
}

void Task_MergeValidMask::task()
{
  m_valid_mask = m_previous->valid_mask().clone();
  cv::bitwise_and(m_valid_mask, m_current->valid_mask(), m_valid_mask);

  m_valid_area = m_previous->valid_area();
  limit_valid_area(m_current->valid_area());

  m_result = m_valid_mask;

  m_previous.reset();
  m_current.reset();
}