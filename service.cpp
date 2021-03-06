/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "DumpstateHAL"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>

#include "DumpstateDevice.h"

using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::dumpstate::V1_0::IDumpstateDevice;
using ::android::hardware::dumpstate::V1_0::renesas::DumpstateDevice;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

int main(int /* argc */, char* /* argv */ []) {
    sp<IDumpstateDevice> dumpstate = new DumpstateDevice;
    configureRpcThreadpool(1, true /* will join */);

    android::status_t status = dumpstate->registerAsService();
    LOG_ALWAYS_FATAL_IF(status != OK, "Could not register IDumpstateDevice");

    joinRpcThreadpool();
}
