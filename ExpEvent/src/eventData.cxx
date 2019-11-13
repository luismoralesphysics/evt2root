#include "eventData.h"
#include <random>

ClassImp(eventData);

eventData::eventData()
{
	Reset();
}
void eventData::Reset()
{
	std::memset(tdc, 0, sizeof tdc);
	std::memset(adc, 0, sizeof adc);
	std::memset(c_adc, 0, sizeof c_adc);
	std::memset(c_adc_hippo, 0, sizeof c_adc_hippo);
	std::memset(c_tdc, 0, sizeof c_tdc);

}
void eventData::SetValue(int crate, int slot, int ch, int value)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);

	if (crate == 0)
	{
		if (ch >= 0 && ch < 32)
		{
			if (slot == 8)
			{
				tdc[ch] = value;

				if (ch == 0)
				{
					c_tdc[0] = (value + dis(gen) - 0.5) * 0.153385 - 20.794914;
				}
				if (ch == 1)
				{
					c_tdc[1] = (value + dis(gen) - 0.5) * 0.154173 - 20.245537;
				}
				if (ch == 2)
				{
					c_tdc[2] = (value + dis(gen) - 0.5) * 0.151334 - 23.346773;
				}
				if (ch == 3)
				{
					c_tdc[3] = (value + dis(gen) - 0.5) * 0.154158 - 23.213186;
				}
				if (ch == 4)
				{
					c_tdc[4] = (value + dis(gen) - 0.5) * 0.152174 - 24.199480;
				}
				if (ch == 5)
				{
					c_tdc[5] = (value + dis(gen) - 0.5) * 0.148630 - 23.764443;
				}
			}
			else if (slot == 4)
			{
				adc[ch] = value;
				if (ch == 0)
				{
					c_adc[0] = (value + dis(gen) - 0.5) *2.89+(	-153.30	);
				}
				if (ch == 1)
				{
					c_adc[1] = (value + dis(gen) - .5) * 2.86+(	-114.47	);
				}
				if (ch == 2)
				{
					c_adc[2] = (value + dis(gen) - .5) * 2.79+(	-143.06	);
				}
				if (ch == 3)
				{
					c_adc[3] = (value + dis(gen) - .5) * 2.83+(	-117.62	);
				}
				if (ch == 4)
				{
					c_adc[4] = (value + dis(gen) - .5) * 2.85+(	-69.26	);
				}
				if (ch == 5)
				{
					c_adc[5] = (value + dis(gen) - .5) * 2.87+(	-30.42	);
				}
				if (ch == 6)
				{
					c_adc[6] = (value + dis(gen) - .5) * 2.82+(	-118.00	);
				}
				if (ch == 7)
				{
					c_adc[7] = (value + dis(gen) - .5) * 2.87+(	-125.17	);
				}
				if (ch == 8)
				{
					c_adc[8] = (value + dis(gen) - .5) * 2.94+(	-127.69	);
				}
				if (ch == 9)
				{
					c_adc[9] = (value + dis(gen) - .5) * 2.85+(	-0.86	);
				}
				if (ch == 10)
				{
					c_adc[10] = (value + dis(gen) - .5)* 2.91+(	-118.77	);
				}
				if (ch == 11)
				{
					c_adc[11] = (value + dis(gen) - .5)* 2.87+(	-80.43	);
				}
				if (ch == 12)
				{
					c_adc[12] = (value + dis(gen) - .5)* 2.83+(	-71.92	);
				}
				if (ch == 13)
				{
					c_adc[13] = (value + dis(gen) - .5)* 2.86+(	-177.09	);
				}
				if (ch == 14)
				{
					c_adc[14] = (value + dis(gen) - .5)* 2.84+(	-163.85	);
				}
				if (ch == 15)
				{
					c_adc[15] = (value + dis(gen) - .5)* 2.82+(	-133.67	);
				}
				if (ch == 16)
				{
				c_adc_hippo[0] = (value + dis(gen) -.5)* 1.90 + (-167.0);
				}
			}
		}
	}
}

// This function is already called in the code.
void eventData::Calibrate()
{
}

void eventData::SetdataStartTime(unsigned int x)
{
	dataStartTime = x;
}



