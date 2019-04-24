#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream outputFile("SoakTest.txt");
	string line;
	char suits[4] = { 'H','C','D','S' };
	if (outputFile.is_open())
	{
		for (int handSuit1 = 0; handSuit1 < 4; handSuit1++)
		{
			for (int handValue1 = 2; handValue1 < 15; handValue1++)
			{
				for (int handSuit2 = 0; handSuit2 < 4; handSuit2++)
				{
					for (int handValue2 = 2; handValue2 < 15; handValue2++)
					{
						if (handValue1 != handValue2 || handSuit1 != handSuit2)
						{
							for (int poolSuit1 = 0; poolSuit1 < 4; poolSuit1++)
							{
								for (int poolSuit2 = 0; poolSuit2 < 4; poolSuit2++)
								{
									for (int poolSuit3 = 0; poolSuit3 < 4; poolSuit3++)
									{
										for (int poolSuit4 = 0; poolSuit4 < 4; poolSuit4++)
										{
											for (int poolSuit5 = 0; poolSuit5 < 4; poolSuit5++)
											{
												for (int poolValue1 = 2; poolValue1 < 15; poolValue1++)
												{
													for (int poolValue2 = 2; poolValue2 < 15; poolValue2++)
													{
														for (int poolValue3 = 2; poolValue3 < 15; poolValue3++)
														{
															for (int poolValue4 = 2; poolValue4 < 15; poolValue4++)
															{
																for (int poolValue5 = 2; poolValue5 < 15; poolValue5++)
																{
																	if ((poolValue1 != handValue1 || poolSuit1 != handSuit1) &&
																		(poolValue2 != handValue1 || poolSuit2 != handSuit1) &&
																		(poolValue3 != handValue1 || poolSuit3 != handSuit1) &&
																		(poolValue4 != handValue1 || poolSuit4 != handSuit1) &&
																		(poolValue5 != handValue1 || poolSuit5 != handSuit1) &&
																								  
																		(poolValue1 != handValue2 || poolSuit1 != handSuit2) &&
																		(poolValue2 != handValue2 || poolSuit2 != handSuit2) &&
																		(poolValue3 != handValue2 || poolSuit3 != handSuit2) &&
																		(poolValue4 != handValue2 || poolSuit4 != handSuit2) &&
																		(poolValue5 != handValue2 || poolSuit5 != handSuit2) &&
																								  
																		(poolValue1 != poolValue2 || poolSuit1 != poolSuit2) &&
																		(poolValue1 != poolValue3 || poolSuit1 != poolSuit3) &&
																		(poolValue1 != poolValue4 || poolSuit1 != poolSuit4) &&
																		(poolValue1 != poolValue5 || poolSuit1 != poolSuit5) &&
																								  
																		(poolValue2 != poolValue1 || poolSuit2 != poolSuit1) &&
																		(poolValue2 != poolValue3 || poolSuit2 != poolSuit3) &&
																		(poolValue2 != poolValue4 || poolSuit2 != poolSuit4) &&
																		(poolValue2 != poolValue5 || poolSuit2 != poolSuit5) &&
																								  
																		(poolValue3 != poolValue1 || poolSuit3 != poolSuit1) &&
																		(poolValue3 != poolValue2 || poolSuit3 != poolSuit2) &&
																		(poolValue3 != poolValue4 || poolSuit3 != poolSuit4) &&
																		(poolValue3 != poolValue5 || poolSuit3 != poolSuit5) &&
																								  
																		(poolValue4 != poolValue1 || poolSuit4 != poolSuit1) &&
																		(poolValue4 != poolValue2 || poolSuit4 != poolSuit2) &&
																		(poolValue4 != poolValue3 || poolSuit4 != poolSuit3) &&
																		(poolValue4 != poolValue5 || poolSuit4 != poolSuit5) &&
																															 
																		(poolValue5 != poolValue1 || poolSuit5 != poolSuit1) &&
																		(poolValue5 != poolValue2 || poolSuit5 != poolSuit2) &&
																		(poolValue5 != poolValue3 || poolSuit5 != poolSuit3) &&
																		(poolValue5 != poolValue4 || poolSuit5 != poolSuit4))
																	{
																		cout << handValue1 << suits[handSuit1] << " " << handValue2 << suits[handSuit2] << endl;
																		cout << poolValue1 << suits[poolSuit1] << " " << poolValue2 << suits[poolSuit2] << " " << poolValue3 << suits[poolSuit3] << " " << poolValue4 << suits[poolSuit4] << " " << poolValue5 << suits[poolSuit5] << endl;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}