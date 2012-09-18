// ==============================
// File:			CArrayIterator.h
// Project:			Einstein
//
// Copyright 1999-2012 by Newton Rsearch Group
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


#ifndef C_ARRAY_ITERATOR_H
#define C_ARRAY_ITERATOR_H


#include "Sim.h"
/*
#include "List.h"
*/
class SingleObject {
};
typedef unsigned int ArrayIndex;
typedef unsigned char BOOL;
class CDynamicArray;


const ArrayIndex kEmptyIndex = 0xFFFFFFFF;

enum IterateDirection
{
	kIterateBackward,
	kIterateForward
};


/**
 The CArrayIterator helps traversing arrays.
 */
class CArrayIterator : public SingleObject
{
public:
	CArrayIterator();
//	CArrayIterator(CDynamicArray * inDynamicArray);
//	CArrayIterator(CDynamicArray * inDynamicArray, BOOL inForward);
//	CArrayIterator(CDynamicArray * inDynamicArray,
//				   ArrayIndex inLowBound,
//				   ArrayIndex inHighBound, BOOL inForward);
//	~CArrayIterator();
//	
//	void			init(void);
//	void			init(CDynamicArray * inDynamicArray,
//						 ArrayIndex inLowBound,
//						 ArrayIndex inHighBound, BOOL inForward);
//	
//	void			initBounds(ArrayIndex inLowBound, ArrayIndex inHighBound, BOOL inForward);
	void			Reset();
//	void			resetBounds(BOOL inForward = kIterateForward);
//	
//	void			switchArray(CDynamicArray * inNewArray, BOOL inForward = kIterateForward);
//	
	ArrayIndex		FirstIndex();
	ArrayIndex		NextIndex();
	ArrayIndex		CurrentIndex();
//	
//	void			removeElementsAt(ArrayIndex index, ArrayIndex inCount);
//	void			insertElementsBefore(ArrayIndex index, ArrayIndex inCount);
//	void			deleteArray(void);
//	
	BOOL			More();
	
	void			Advance();
	
	CArrayIterator*	AppendToList(CArrayIterator *inList);
	CArrayIterator*	RemoveFromList();
	
	SIM_GET_SET_W(CDynamicArray*, DynamicArray)		//  +0: the associated dynamic array
	SIM_GET_SET_W(ArrayIndex, CurrentIndex)			//  +4: current index of this iteration
	SIM_GET_SET_W(ArrayIndex, LowBound)				//  +8: lower bound of iteration in progress
	SIM_GET_SET_W(ArrayIndex, HighBound)			// +12: upper bound of iteration in progress
	SIM_GET_SET_B(BOOL, IterateForward)				// +16: if iteration is forward or backward
	SIM_GET_SET_W(CArrayIterator*, PreviousLink)	// +20: link to previous iterator
	SIM_GET_SET_W(CArrayIterator*, NextLink)		// +24: link to next iterator
};


#endif	// C_ARRAY_ITERATOR_H

