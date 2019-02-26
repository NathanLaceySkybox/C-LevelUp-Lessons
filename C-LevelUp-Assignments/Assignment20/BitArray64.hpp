#pragma once

class BitArray64
{
public:
	BitArray64();

	int Get();
	void Return(int index);
	void Set(int index, bool value);
	bool Value(int index);

private:
	static constexpr int kArraySize = 64;

	long long mBits;
	long long mBitsInUse;
};