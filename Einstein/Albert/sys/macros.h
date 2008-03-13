// File:                        sys/macros.h
// Project:                     Albert
//
// Copyright 2003-2008 by Matthias Melcher (albert@matthiasm.com).
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
// ==============================
// $Id$
// ==============================

#ifndef ALBERT_SYS_MACROS_H
#define ALBERT_SYS_MACROS_H


#ifdef ALBERT_OS_STANDALONE

/**
 * Generates code for a class member and read and write access.
 * The member is private and followed by an underscore: XXX_ . Direct access to the
 * member will not work under Einstein. Instead use the provided functions
 * GetXXX() and SetXXX(x)
 */
#define ALBERT_CLASS_MEMBER(type, name) \
  public:  type Get##name() { return name##_; } \
           void Set##name(type v) { name##_ = v; } \
  private: type name##_;

/**
 * Generates code for a class member array and read and write access.
 * The member is private and followed by an underscore: XXX_ . Direct access to the
 * member will not work under Einstein. Instead use the provided functions
 * GetXXX() to retreive the address of the array, SetXXX(ix, val) to set the value
 * of an indexed element, and Get(ix) to read an element in the array.
 */
#define ALBERT_CLASS_MEMBER_ARRAY(type, name, size) \
  public:  type *Get##name() { return name##_; } \
           type Get##name(KUInt32 ix) { return name##_[ix]; } \
           void Set##name(KUInt32 ix, type v) { name##_[ix] = v; } \
  private: type name##_[size];


#else

/*
 * The macros below are the Einstein equivalent to the very simple macros above.
 * The functions generated by these macros make emulated code behave exactly
 * like native code in the Albert environment.
 */

#define ALBERT_CLASS_MEMBER(type, name) \
  public:  type Get##name() { return (type)getMem32( (KUInt32)&name##_ ); } \
           void Set##name(type v) { setMem32( (KUInt32)&name##_, (KUInt32)v ); } \
  private: type name##_;

#define ALBERT_CLASS_MEMBER_BYTE(type, name) \
  public:  type Get##name() { return (type)getMem8( (KUInt32)&name##_ ); } \
           void Set##name(type v) { setMem8( (KUInt32)&name##_, (KUInt8)v ); } \
  private: type name##_;

#define ALBERT_CLASS_MEMBER_ARRAY(type, name, size) \
  public:  type *Get##name() { return (type*)(&name##_); } \
           type Get##name(KUInt32 ix) { return (type)getMem32( (KUInt32)(&(name##_[ix])) ); } \
           void Set##name(KUInt32 ix, type v) { setMem32( (KUInt32)(name##_[ix]), (KUInt32)v ); } \
  private: type name##_[size];

/**
 * Create a call from the emulator into native Albert OS code.
 */
#define ALBERT_FUNCTION_STUB(address, name) \
  JITInstructionProto(name##_Stub); \
  TROMPatch p##name(address, name##_Stub, #name); \
  JITInstructionProto(name##_Stub)

/**
 * Create a call from the emulator into native Albert OS code.
 */
#define ALBERT_METHOD_STUB(address, klass, name) \
  JITInstructionProto(klass##_##name##_Stub); \
  TROMPatch p##name(address, klass##_##name##_Stub, #klass"::"#name); \
  JITInstructionProto(klass##_##name##_Stub)

#endif


#endif
// ALBERT_SYS_MACROS_H
