#pragma once

#include <chrono>
#include <cstdint>

namespace pe {

	class Timer
	{
	public:
		Timer();
		~Timer();

		void Start();
		void Stop();
		void Reset();

		int64_t GetNow();
	private:
		std::chrono::steady_clock::time_point m_TimeBegin;
		std::chrono::steady_clock::time_point m_TimeEnd;

		bool m_IsStopped;
	};

}