/*
  Copyright 2017 Detlef Urban <onkel@paraair.de>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THIS SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef OALSA_H
#define OALSA_H

#include <alsa/asoundlib.h>

// number of input channels
#define NUM_CHANNELS 16

#define CTL_ROUTE                           "name='Route'"
#define CTL_NAME_BYPASS                     "name='Bypass'"
#define CTL_NAME_BUS_OUT                    "name='Buss out'"
#define CTL_NAME_MASTER_MUTE                "name='Master mute'"
#define CTL_MASTER                          "name='Master'"

#define CTL_NAME_FADER                      "name='Fader'"
#define CTL_NAME_PAN                        "name='Pan'"
#define CTL_NAME_MUTE                       "name='Mute'"
#define CTL_NAME_SOLO                       "name='Solo'"
#define CTL_NAME_PAN                        "name='Pan'"
#define CTL_NAME_PHASE                      "name='Phase'"
#define CTL_NAME_EQ_ENABLE                  "name='EQ enable'"
#define CTL_NAME_EQ_LOW_LEVEL               "name='Low gain'"
#define CTL_NAME_EQ_LOW_FREQ                "name='Low freq'"
#define CTL_NAME_EQ_MIDLOW_LEVEL            "name='Mid low gain'"
#define CTL_NAME_EQ_MIDLOW_FREQ             "name='Mid low freq'"
#define CTL_NAME_EQ_MIDLOWWIDTH_FREQ        "name='Mid low Q'"
#define CTL_NAME_EQ_MIDHIGH_LEVEL           "name='Mid high gain'"
#define CTL_NAME_EQ_MIDHIGH_FREQ            "name='Mid high freq'"
#define CTL_NAME_EQ_MIDHIGHWIDTH_FREQ       "name='Mid high Q'"
#define CTL_NAME_EQ_HIGH_LEVEL              "name='High gain'"
#define CTL_NAME_EQ_HIGH_FREQ               "name='High freq'"
#define CTL_NAME_CP_THRESHOLD               "name='Threshold'"
#define CTL_NAME_CP_GAIN                    "name='Gain'"
#define CTL_NAME_CP_ATTACK                  "name='Attack'"
#define CTL_NAME_CP_RELEASE                 "name='Release'"
#define CTL_NAME_CP_RATIO                   "name='Ratio'"
#define CTL_NAME_CP_ENABLE                  "name='Comp enable'"

#define RESET_VALUE_DELAY                   1000

#define CTL_NAME_CHANNEL_ACTIVE             "channel_active"
#define CTL_NAME_METER                      "name='Meter'"

class OAlsa {
public:
    OAlsa();
    virtual ~OAlsa();
    
//     open alsa device
    int open_device();

//     close alsa device
    void close_device();
    
//     get control element current value
    int getInteger(const char* name, int channel_index);
    
//     set control element integer value
    void setInteger(const char* name, int channel_index, int value);
    
//    get controls boolean value
    bool getBoolean(const char* name, int ch);
 
//    set control boolean value
    void setBoolean( const char* name, int channel_index, bool value);
    
//    get an array of integers (meter values)
    int getIntegers(const char* name, int vals[], int count);
    
    // VScale value change slot
    void on_range_control_changed (int n, const char* control_name, Gtk::VScale* control, Gtk::Label* label);
    
//    ODial value change slot
    void on_dial_control_changed (int n, const char* control_name, ODial* control);
    
//    ToggleButton set boolean value slot
    void on_toggle_button_control_changed (int n, const char* control_name, Gtk::ToggleButton* control);    
    
//    ToggleButton set boolean value slot
    void on_active_button_control_changed (int n, const char* control_name, Gtk::ToggleButton* control);    
    
//    Slot for comboBox change event
    void on_combo_control_changed (int n, const char* control_name, Gtk::ComboBoxText* control);
    
    int sliderTodB(int pos);
    int dBToSlider(int dB);
    
    
//* HCTL handle of the Tascam card 
    snd_hctl_t *hctl;    

    int meters[34];
private:

//    * Id of the Tascam US-16x08 alsa card 
    int cardnum;
    
//     identify Tascam alsa card number
    int get_alsa_cardnum();
    
//     retrieve control element by name
    snd_hctl_elem_t* get_ctrl_by_elem(const char* name);
    
//     create control name including its index
    char* create_ctrl_elem_name(const char* name, int index, char* result[], size_t size);

    
};

#endif /* OALSA_H */

