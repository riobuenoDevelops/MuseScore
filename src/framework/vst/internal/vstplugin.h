/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MU_VST_VSTPLUGIN_H
#define MU_VST_VSTPLUGIN_H

#include <mutex>

#include "modularity/ioc.h"
#include "io/path.h"
#include "async/asyncable.h"
#include "audio/iaudiothreadsecurer.h"

#include "vsttypes.h"
#include "vsterrors.h"

namespace mu::vst {
class VstPlugin : public async::Asyncable
{
    INJECT_STATIC(vst, audio::IAudioThreadSecurer, threadSecurer)

public:
    VstPlugin(PluginModulePtr module);

    const std::string& name() const;

    PluginViewPtr view() const;
    PluginComponentPtr component() const;

    bool isValid() const;

private:
    void load();

    PluginModulePtr m_module = nullptr;
    PluginProviderPtr m_pluginProvider = nullptr;
    mutable PluginComponentPtr m_pluginComponent = nullptr;
    mutable PluginViewPtr m_pluginView = nullptr;

    mutable std::mutex m_mutex;
};
}

#endif // MU_VST_VSTPLUGIN_H
