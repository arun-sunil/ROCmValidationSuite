/********************************************************************************
 *
 * Copyright (c) 2018 ROCm Developer Tools
 *
 * MIT LICENSE:
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/
#ifndef PEQT_SO_INCLUDE_ACTION_H_
#define PEQT_SO_INCLUDE_ACTION_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <pci/pci.h>
#ifdef __cplusplus
}
#endif

#include <vector>
#include <string>

#include "rvslib.h"

using std::vector;
using std::string;

class action: public rvs::lib::actionbase {
 public:
    action();
    virtual ~action();

    virtual int property_set(const char*, const char*);
    virtual int run(void);

 private:
    vector<string> device_prop_gpu_id_list;  // the list of all gpu_id
                                             // in the <device> property

    string action_name;
    bool bjson;
    void* json_root_node;

    // PCIe capabilities stuff
    bool get_gpu_all_pcie_capabilities(struct pci_dev *dev, unsigned short int gpu_id);

    // configuration properties getters
    bool property_get_device(int *error); // gets the device property value (list of gpu_id)
    //from the module's properties collection
    void property_get_action_name(void);  // gets the action name
    int property_get_deviceid(int *error);  // gets the deviceid

 protected:
};

#endif  // PEQT_SO_INCLUDE_ACTION_H_
