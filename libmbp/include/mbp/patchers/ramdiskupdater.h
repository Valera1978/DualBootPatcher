/*
 * Copyright (C) 2014-2017  Andrew Gunnerson <andrewgunnerson@gmail.com>
 *
 * This file is part of MultiBootPatcher
 *
 * MultiBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MultiBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MultiBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>

#include "mbp/patcherconfig.h"
#include "mbp/patcherinterface.h"


namespace mbp
{

class RamdiskUpdater : public Patcher
{
public:
    explicit RamdiskUpdater(PatcherConfig * const pc);
    ~RamdiskUpdater();

    static const std::string Id;

    virtual ErrorCode error() const override;

    // Patcher info
    virtual std::string id() const override;

    // Patching
    virtual void setFileInfo(const FileInfo * const info) override;

    virtual bool patchFile(ProgressUpdatedCallback progressCb,
                           FilesUpdatedCallback filesCb,
                           DetailsUpdatedCallback detailsCb,
                           void *userData) override;

    virtual void cancelPatching() override;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

}
