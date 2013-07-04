class ZakladniTrida
{
	private:
		static int m_varStatic;	// promenna k nicemu...
	
	public:
		virtual void fnZakladni(int n)
		{
			int a = 4;
			switch(a)
			{
				case 1: a+=2; break;
				case 2: a++; break;
				case 3: a--; break;
				case 4: a*=2; break;
				case 5: a/=2; break;
				case 6: a*=3; break;
				case 7: a-=3; break;
				case 8: a/=3; break;
				case 9: a =2; break;
				default: a = 0;
			}
			while(n > a)
			{
				--n;
			}
		}
		
		void fnfnfn();
};

class PrvniTrida : public ZakladniTrida
{
	int m_a, m_b, m_c;
	
	public:
		static void fnStatPrvni();
		virtual void fnZakladni(int n);
		void metoda()
		{
			/*
			 * Tenhle komentar ma velice dulezite poslani oznamit, ze nic neoznamuje
			 * a slouzi jen ke zvyseni COMMDENS :-)
			 */
			bool a = true;
			bool b = false;
			if(a && m_a)
				if(m_c && m_b)
					if(b && m_c)
						if(m_a && m_c)
							return;
				
			if(((3 + 6 > 10) + (1 + 2 < 4)) == 2)
				return;
			else
			{
				int k = 2;
				for(int i = 0; i < 10; i = i + 1)
					if(k == i)
						break;
			}
			//
			fnStatPrvni();
			fnfnfn();	// tohle je v rodicovske tride
			fnZakladni(5);
			//
			for(int i = 0; i < 5; i = i + 1)
			{
				int a = i;
				continue;
				a = 333;
			}
		}
};

namespace Prostor
{
	class DalsiTrida : public PrvniTrida
	{
		public:
			void fnDalsi();
			
			ZakladniTrida *atribut;
	};
}

int main()
{
	//
	// While cyklus
	//
	int x = 5;
	while(x > 0)
		x = x - 1;
	//
	// Do cyklus
	//
	do
	{
		x = x + 1;
	} while(x < 10);
	//
	// Vnoreny blok
	//
	{
		int a = 5;
	}
	//
	// spousta For cyklu
	//
	for(int i = 0; i < 10; i = i + 1)
		for(int j = 0; j < 10; j = j + 1)
			for(int k = 0; k < 10; k = k + 1)
				;
	//
	// Volani metody tridy
	//
	PrvniTrida pt;
	pt.metoda();
	//
	// Koncime...
	//
	return 0;
}
