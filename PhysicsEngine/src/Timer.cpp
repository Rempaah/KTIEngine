#include "Timer.h"

namespace pe {

	Timer::Timer()
		: m_IsStopped(false)
	{
		m_TimeBegin = std::chrono::steady_clock::now();
		m_TimeEnd = std::chrono::steady_clock::now();
	}
	
	Timer::~Timer()
	{}

	void Timer::Start()
	{
		m_IsStopped = false;
	}

	void Timer::Stop()
	{
		m_IsStopped = true;
	}

	void Timer::Reset()
	{
		m_IsStopped = false;
		m_TimeBegin = std::chrono::steady_clock::now();
	}

	int64_t Timer::GetNow()
	{
		if (!m_IsStopped)
			m_TimeEnd = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::microseconds>(m_TimeEnd - m_TimeBegin).count();
	}

}