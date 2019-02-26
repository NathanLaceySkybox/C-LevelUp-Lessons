#include "BitArray64.hpp"

bool BitArray64::operator==(const BitArray64& rhs) const 
{
	return mBits == rhs.mBits && mBitsInUse == rhs.mBitsInUse;
}

bool BitArray64::operator!=(const BitArray64& rhs) const 
{
	return mBits != rhs.mBits || mBitsInUse != rhs.mBitsInUse;
}

int BitArray64::Get()
{
	int position{ 0 };
	decltype(mBitsInUse) nextBitToUse{ mBitsInUse + 1 };
	
	if (nextBitToUse == 0) 
	{
		return -1;
	}

	for (decltype(mBitsInUse) i{ 1 }; !(i & nextBitToUse); i <<= 1, ++position);

	mBitsInUse |= ((decltype(mBitsInUse))1 << (decltype(mBitsInUse))position);

	return position < kArraySize ? position : -1;
}

void BitArray64::Return(int index) 
{
	if (index >= 0 && index < kArraySize) 
	{
		mBitsInUse &= ~(1 << index);
	}
}

void BitArray64::Set(int index, bool value) 
{
	if (index < 0 || index >= kArraySize)
		return;

	if (value) 
	{
		mBits |= (1 << index);
	}
	else 
	{
		mBits&= ~(1 << index);
	}

	mBitsInUse |= (1 << index);
}

bool BitArray64::Value(int index) 
{
	if (index < 0 || index >= kArraySize)
		return false;

	return (mBits & (1 << index)) != 0;
}
