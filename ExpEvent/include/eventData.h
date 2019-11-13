#ifndef EVENTDATA_H
#define EVENTDATA_H

#include "TObject.h"
#include <iostream>
#include <cstring>

///Traditional data acquisiton setup at Univ. of Notre Dame 2013
/**This is a multipurpose setup used at ND for data acquistion. It consists
 * of a ADC in slot ## and a TDC in slot ##
 */
class eventData : public TObject
{
  private:
	int tdc[32];
	int adc[32];
	double c_adc[16];
	double c_adc_hippo[16];
	double c_tdc[16];
	unsigned int dataStartTime;

  public:
	///Default Constructor
	eventData();
	///Reset the current values.
	void Reset();
	///Record the value from the specified location.
	void SetValue(int crate, int slot, int ch, int value);
	///Calibrates the data from one event.
	void Calibrate();
	void SetdataStartTime(unsigned int x) ;

	ClassDef(eventData, 1);
};

#endif
