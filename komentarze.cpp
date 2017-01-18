#include <iostream>
#include <string>
using namespace std;
int main()
{
	int dl, il = 0;
	string wyraz, w;
	bool p = false;

	for (;;)
	{
	
		getline(cin, wyraz);
		if (wyraz.empty())
		{
			il++;
		}
		if (il == 2)
			break;

		dl = wyraz.length();
		for (int i = 0; i < dl; i++)
		{

			if (wyraz[i] == '"' || wyraz[i] == '\'')
			{
				cout << wyraz[i];
				

				while (wyraz[i] != '"' || wyraz[i] != '\'')
				{
					i++;
					cout << wyraz[i];
					if (wyraz[i] == '"' || wyraz[i] == '\'')
						break;

				}

			}
			else
			{


				if (p == true)
				{
					for (int j = i; j < dl; j++)
					{
						if (wyraz[j] == '*'&&wyraz[1 + j] == '/')
						{
							i++;
							p = false;
							wyraz[j] = false;
							wyraz[1 + j] = false;
							break;
						}
						wyraz[j] = false;

					}
				}

				if (wyraz[i] == '/' && wyraz[1 + i] == '/')
				{

					for (int j = i; j < dl; j++)
					{
						wyraz[j] = false;
					}
				}
				if (wyraz[i] == '/'&&wyraz[1 + i] == '*')
				{
					wyraz[i] = false;
					wyraz[1 + i] = false;
					p = true;
					i += 2;
					for (int k = i; k < dl; k++)
					{


						if (wyraz[k] == '*'&&wyraz[1 + k] == '/')
						{
							p = false;
							wyraz[k] = false;
							wyraz[1 + k] = false;

							break;
						}

						wyraz[k] = false;

					}
				}

				if (wyraz[i] == false)
				{
					while (wyraz[i] == false)
					{
						break;
					}
					//i--;
				}
				else
				{
					cout << wyraz[i];
					il = 0;
				}
			}
			
		}
		cout << endl;
	}
	return 0;
}
