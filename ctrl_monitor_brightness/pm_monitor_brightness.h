#pragma once
 
//
#include <physicalmonitorenumerationapi.h>
#include <highlevelmonitorconfigurationapi.h>
 
 
class pm_monitor_brightness
{
public:
    pm_monitor_brightness(void);
    virtual ~pm_monitor_brightness();
 
    /*
    @brief: 增加亮度
    @param：const unsigned int offset - 步长，最大为100， 若超过100，将亮度设置为最大
    @return： int
            0 - 成功
            1 - 失败，设置失败
    */
    int increase(const unsigned int offset = 10);
 
 
    /*
    @brief: 降低亮度
    @param：const unsigned int offset - 步长，最大为100， 若超过100，将亮度设置为低
    @return： int
            0 - 成功
            1 - 失败，设置失败
    */
    int decrease(const unsigned int offset = 10);
 
private:
 
    // 设置屏幕亮度
    void set_monitor_brightness(const unsigned int bright);
 
    void init();
 
private:
    enum
    {
        max_offset_100 = 100,
 
    };
 
    struct pm_brightness_val
    {
        // 当前亮度值
        int     _cur;
        // 显示器最大亮度
        int     _max;
        // 显示器亮度最低值
        int     _min;
 
        void zero()
        {
            memset(this, 0, sizeof(pm_brightness_val));
        }
 
        pm_brightness_val()
        {
            zero();
        }
    };
 
    //
    BOOL        _is_init_success;
    HANDLE      _handle_cur_monitor;
 
    HMONITOR    _monitor;
    DWORD       _physical_monitor_number;
 
    LPPHYSICAL_MONITOR   _physical_monitor;
    //
    pm_brightness_val   _brightness_val;
 
};
