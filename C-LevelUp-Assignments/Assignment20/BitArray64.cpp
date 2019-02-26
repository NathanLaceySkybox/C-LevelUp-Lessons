#include "BitArray64.hpp"

BitArray64::BitArray64() 
{
}

int BitArray64::Get() 
{
	return 0;
}

void BitArray64::Return(int index) 
{
	mBits &= ~(1 << index);
}

void BitArray64::Set(int index, bool value) 
{
	
}

bool BitArray64::Value(int index) 
{
	return (mBits & (1 << index)) != 0;
}
