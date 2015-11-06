//  File:   NamedPipeI2C_Device.h
//  Stream buffer implementation backed by a pair of named pipes
//
//  This file is part of the Ember firmware.
//
//  Copyright 2015 Autodesk, Inc. <http://ember.autodesk.com/>
//    
//  Authors:
//  Jason Lefley
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  THIS PROGRAM IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL,
//  BUT WITHOUT ANY WARRANTY; WITHOUT EVEN THE IMPLIED WARRANTY OF
//  MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  SEE THE
//  GNU GENERAL PUBLIC LICENSE FOR MORE DETAILS.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, see <http://www.gnu.org/licenses/>.

#ifndef MOCKHARDWARE_NAMEDPIPEI2C_DEVICE_H
#define MOCKHARDWARE_NAMEDPIPEI2C_DEVICE_H

#include "I_I2C_Device.h"

#include <string>

class NamedPipeI2C_Device : public I_I2C_Device
{
public:
    NamedPipeI2C_Device(const std::string& readPipePath,
                        const std::string& writePipePath);
    ~NamedPipeI2C_Device();

    bool Write(unsigned char data) const;
    bool Write(unsigned char registerAddress, unsigned char data) const;
    bool Write(unsigned char registerAddress, const unsigned char* data, 
               int length) const;
    unsigned char Read(unsigned char registerAddress) const;

private:
    NamedPipeI2C_Device(const NamedPipeI2C_Device&);
    NamedPipeI2C_Device &operator=(const NamedPipeI2C_Device&);
    
    int _readFd;
    int _writeFd;
};

#endif  // MOCKHARDWARE_NAMEDPIPEI2C_DEVICE_H

