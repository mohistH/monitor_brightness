#include "stdafx.h"

#include "pm_monitor_brightness.h"
#include <winuser.h>

pm_monitor_brightness::pm_monitor_brightness()
    : _is_init_success(FALSE)
    , _handle_cur_monitor(NULL)
    , _monitor(NULL)
    , _physical_monitor_number(0)
    , _physical_monitor(NULL)
{
    init();
}

pm_monitor_brightness::~pm_monitor_brightness()
{
    if (NULL != _physical_monitor)
        DestroyPhysicalMonitors(_physical_monitor_number, _physical_monitor);

    if (NULL != _physical_monitor)
    {
        free(_physical_monitor);
        _physical_monitor = NULL;
    }
}


int pm_monitor_brightness::increase(const unsigned int offset/*=10*/)
{
    pm_brightness_val& param = _brightness_val;

    // 没有初始化成功
    if (!_is_init_success)
        return 1;

    // 已经打到最大值
    if (param._cur == param._max)
        return 0;

    param._cur = (max_offset_100 == offset) ? param._max : (param._cur + offset);
    if (param._cur > param._max)
        param._cur = param._max;

    set_monitor_brightness(param._cur);

    return 0;
}

int pm_monitor_brightness::decrease(const unsigned int offset/* = 10 */)
{
    pm_brightness_val& param = _brightness_val;

    // 没有初始化成功
    if (!_is_init_success)
        return 1;

    // 已经打到最大值
    if (param._cur == param._min)
        return 0;

    param._cur = (max_offset_100 == offset) ? param._max : (param._cur - offset);
    if (param._cur < param._min)
        param._cur = param._min;

    set_monitor_brightness(param._cur);

    return 0;
}


// 设置屏幕亮度
void pm_monitor_brightness::set_monitor_brightness(const unsigned int bright)
{
    if (_is_init_success)
        SetMonitorBrightness(_handle_cur_monitor, bright);
}


void pm_monitor_brightness::init()
{
    _monitor = ::MonitorFromWindow(NULL, MONITOR_DEFAULTTOPRIMARY);

    _is_init_success = GetNumberOfPhysicalMonitorsFromHMONITOR(_monitor, &_physical_monitor_number);

    if (_is_init_success)
    {
        _physical_monitor = (LPPHYSICAL_MONITOR)malloc(_physical_monitor_number * sizeof(LPPHYSICAL_MONITOR));
        if (NULL != _physical_monitor)
        {
            _is_init_success = GetPhysicalMonitorsFromHMONITOR(_monitor, _physical_monitor_number, _physical_monitor);
            if (_is_init_success)
            {
                DWORD   max_val = 0;
                DWORD   cur_val = 0;
                DWORD   min_val = 0;

                HANDLE ppp = _physical_monitor[0].hPhysicalMonitor;
				WCHAR arr[PHYSICAL_MONITOR_DESCRIPTION_SIZE] = {0};
				memcpy(arr, _physical_monitor[0].szPhysicalMonitorDescription, sizeof(_physical_monitor[0].szPhysicalMonitorDescription));
                _is_init_success = GetMonitorBrightness(ppp, &min_val, &cur_val, &max_val);

                _brightness_val._cur = cur_val;
                _brightness_val._max = max_val;
                _brightness_val._min = min_val;

                _handle_cur_monitor = ppp;
            }
        }
		else
		{
			_is_init_success = false;
		}
    }
}