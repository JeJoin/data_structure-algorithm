#include <common.h>
#if PRIMARY_ALGORITHMS_STRING

/*��дһ���������������ǽ�������ַ�����ת������
�����ַ������ַ����� char[] ����ʽ������
��Ҫ�����������������Ŀռ䣬
�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ����*/
void reverseString(vector<char>& s)
{
	reverse(s.begin(), s.end());
}

void testReverseString()
{
	vector<char> s = { 'H','a','n','n','a','h' };
	reverseString(s);
	for (auto c : s) {
		cout << c << " ";
	}
	cout << endl;
}

/*����һ���ַ������ҵ����ĵ�һ�����ظ����ַ�����������������
��������ڣ��򷵻� -1*/
int firstUniqChar(string s)
{
	int idx = s.length();
	int mapIdx[26] = { -1 };
	int mapCount[26] = { 0 };
	for (int i = 0; i < s.length(); ++i) {
		mapIdx[s[i] - 'a'] = i;
		mapCount[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (mapCount[i] == 1 && mapIdx[i] < idx) {
			idx = mapIdx[i];
		}
	}

	return idx == s.length() ? -1 : idx;
}

void testFristUniqChar()
{
	string s = "jnaprrmwbbujwrgqqtccvkjvxwiimcvmokrdsbgpubcwlveeqeprvoofeepsntdrujehsthrdwunjfedhltnarwsqjxbtuwnnkklsqqmhxthicnwthvenkcvuxhxvpxihelaqariwlxtamqmocwawtcnbmilvswcurgffljwjlhbjknfpkwqckvtfbjwsosetpttjabnjxdcmwtcnievjilfcgtxmdmwmheivjrfvxvnxosrsmiwtvgnwdnwtbtogrwwxuhpetcdmttnvgttxilclxiuhpaodvmnbkwkakncbvwdgwfmitvfamuxapsfsculbtmwqvteqmsvndnctebfvaqkghculsgcjoctdmhaxqasspmermcsbencbaabxdlkxfpcdpxhaaxdnabtclwfwpcrrstxeodjnoechotqkvqoxovnoqvflligxumlttvbccimhqelfxlnotqvwfbkqogjjisxujsjgrehlosbiwpqtoraqihuvkvtaugcirbkrthlmjernseopgqansjutvvtfjxufudllhkaqgtldcupaexegdpbqxvrgxownqameonhaqwxtxetaitmctblfcfwvfdhwghvejhpuwootbxkvkhiarwlcegbrffpcfixtgbqfpthuqknrrbrkpwqqpakrnepxhmrsvktrmudomimlxjhhlkknbtspocopsdlxqtxcnjabnhnksqaxocsltfhcqmmrhmotndmwseqgshsitfgcxfhjebektvrfoqbhfdlxlkdlebsubsiiqerwwngxwlotppejqddepopkdfwoomxrpgjmhbhblwslrqidgsuexnwbpkfgbnknwuokahoiqhofvtmdxjhbtkqcpbpubnbutvqibeuewobrmbidsptstdlenbeqpuewwcinkshfncdhesvsqfahharpptnddjmtjtetsbbeeduhvvsirsoiwcjkwpjleeautxhjlbsxntfcjdpmfhwfbbehkurjuoihdhoitbiawhnggtfielhwrubvcctwbpvocstgdjnfisevfgstghcddmiuqtramowhqrnelsratclnwdjvktfvcijmcudbvmlundeckmsxghjqblpxbodknbvvbqxheivtqrbrcosmdsomwwwplrbldplinnxuqdlgkcthbbbwqtllmlngatrjfrmlwlswlmfmexkgquvuobxmflmupncsdhgxttrplmevmihmhaaafnswpnmccweivtlnwmdgbdwbsmbdwejjfovtdsuoxhqctsdlnqadvioaimqrejrhwvgcijmchiepmxmdjujwotjcexnidhpchsatatnucadrbhilrkuxogbxxgpprvdcjmagjaowxpcpsvpnxceolpfhkboopmniudiluxxxqpdbpppqjuglggvcspdnmtwcaqplrbjodfnpqvctjouwhesqsiuuktnrelveavtvjerbmixantnagalcifutptcncdlxrdvtkcopmipwvjrhktrwggikfmghibimdfxqfpujburftrbeensocscrcoafhefuxrsumudxavvvvsequnaavkrqwiabhnqnfhvhnjmrestgnmcbkedognnpdcpsqetbfabbrvwameeqbburorboxmxhxfuxjinxxefkibbspdxdkprpavukwxwgmrxktkhgckrtsuwagofqhojspxtjevkwinbsojaaptvkhpmtjvunkpfeeqhljoefmsbxkgieowsiojtkarotjkeuhqxqfelfhqxrhqqspmxwqlmulcttfookqwlqiehfdgdifixskmusnfoljxbdoddohtttrjrmweomtfvupxsovgbwljcnmtualgajbbqebdpvcasivvaaioomrawaxdiavabkquuumlxdsjxwfvwcvhmxldtlogagnixwwdgmpluodptghxvtnolorktqcskslhavlvmmkmigvtxqlmdtawtrsofwlpbvxnhaouquewdmhubfqulcwffahhsfrwkvibrnjvsmoqegktllqxshxlqmrmrvmhhlqlqokdreaklogxftrdsmcbfdnocwdjxqfutjclfesniktbfomtcrbxsowmfqxvckaukqiqofmbuubrncjnlekmjntptlicrtisnboqvfnffkxgvrxbtwgacjtxthwrtkxxngklbfgkwgpatkaruxmfdahtgmbbawtlcwfscwhpuxxqjuscwhgjguhlclilijfvcjhvroinjvigwropipseddtabcfxecfvhxidnpjdeajktaunsfkxqptcddwutbteaqanwqjkoaeshbeputljhpwqwemcogpswmocviksovpjkmvdxxidasvdupxturqoxllljbksmhtvejrjslqfbcqtncoevkqbofhpscstqwqgoiocfgsoegxxxxtirrfsikkxitjmdkgwhrvwihipiocpufefjohcpsetmebgumvsafwmeiqxwsimductmkirsgmsnnaqtkmuxkavqqtpnclgventdlpojmunegidbvemprfifxipngbebvmnusdbvgstihxwvwfkvttwcfbggodhphbibafmvswfjindpdxvtwtxpsuejliohsknsdfejsccxsmhqwsvaufkugctndkcsgilfvdmcuvtdtcmxofletixkjtisxxtptltmvgjhcgpufbcmtchxvgpaepgjqqixjlegsqgatoiswxiauxqcjncpvncrenrrjxpuwhjfxvtoafhctnxfpwxvvxxkngpvrimnqecpodkpbcxcptlohrhmvllfstclkpkrixkgqivftapqqlnpiocutsojctjunkcbghjavtlbfvhvwlehumodbmboppvpbbddkgohfvfcociarurptuwtfiuvapgungwkmsckaoliqhssrgunlhqujqwefdtdlpsleuvbgwedsmukpbmundvumcqowdmnsfiikuffxfquejxqbfsrrqufohrqlgksbqxagjnnmkqswvtmijnwpawwxpsuuovakialjnlclguoajoxfwgsabcaxcljbrmjuvlkjwicobdhcndioemfcujkghlasiqepgpuivlhltgvnbqhvtqqpcsuupcxxkiktnvbucnammeqhvovqdssnaowbsbqbbnbriekhnnoxmwjjiebblrdgjnjvqilolxtxavghfmqokuhmdltpfnurtoeijowxrfigmxfomboaxvcgokdchiefachlvelvlppwwtativbfljlrrccbcpdewqlelcchroqiujgwcqqvwkjdmkpgwfjvwjxumhjmdclchahhsbtixfuwgtdqcihapeeeqlcgqsbwhbdwpacwifnrrfnxpievlcqshhmejxjsutttdxoxhalmthfuwwbeitfajlinobdivxgoudwtvgoonkdfvkvnxocnfwnthxppuuvhdhlssawjovqdmlqailiaejlvubgwpthwijdvwgeuardgnrcvluodwdtdmqapxlettbasqhpxjnvhoouvqomndflnbedjmfuhlikkbdqkdkeurangwmlothgtbmjmgjaqbgqgrmogmxkpehfkwejwfajwnbbqughqgcjeihbrmoxwpunhigrftawmesenhvbvxfqogxjuvublegupmtaltauoqaithnhbpwklskphvlkukosasdqawitfhdiduxqknojswiclotrtieqervinuhmhccrdgkucqevvikcwgtxxpxnkcbaiewoojnnuehlijretbqqsgedaxirjwrjshuramvlxiggmqfqubjlgfongqgndkdcuwsohdslcignwfxaihglrvqgjjchhbplupiusftgxvqooiqfxforvmcejemkncwfmsflidrtupttuipnjbsurlvswxddfuphlbsttnuslvaligftgermfkjfilpehqujaswfsdducaggksjugwmrijfhppjueosufhkbnfoptbgnkmucsgteeakhufrtkwtpbovnmcgwvoxxiufuaoveagxfftgcsphseqidputgaqtvvjnkjedsnmfkltranlffwukkgrmjuwxvhfefgbmvrcmvhdjfbiwjpmucrksojsfrhorufvbvnqlghexkhhkfpgoubomgxsfbgvfxqabcjotovnloaqicwlxhextxwhgltjpxgjvnwtdmaamjdsaxelaedlpmgbbjvealwknfsamihtdmphumrgqjptxcapgdweadcrqcpfvdexxgwvrbwdaiohdtsdupftoxbhwndkhtgebxxfjhbmhbchmwndtpspkileavqxjlvcaisxenthwcjlsdcamkuivfahocutmirivqxlstnnnfncelpkxrnqxhikhfbaqmsaxhwassvgtbnftngrltmvpnlduuoemwiipfxaurfjbhjmxjwfrqsrghrdnclirhlrntsjbauaowrxhiwviqfcdvskbmitwfulaqpmbqkrdgvgtbasbewqhipxqenpekbfjvoblqwfhxfiemleedvncxgudbsccolrxqahiqcudkrpsjhlqvtidkqhkupojxlvtldipqvoggjjermhfdgqcsgjelmraxpsegqcrrpkbmvhdtshmuhgqooccbjdagrqlhiggcqsednqwajefqpsnwcktlwojshoqijmveimodsooxbphqfuitjiqduasvlosjnlwnirausxdicndlilkesorqjtupmorqtfsaoajhwemdurrbcbdrxcvshvogrhohdqjkttclpvrbqkqdsesdpnfsmpjuerjvufknqacimklrmhaihfhbkwqpkavaeecdimgitqcpulclcbcalmltqhobxkjlrppaonulflkxrxvqaagdfqwbrgjjvlfutedmwhnhxjbakpvpqmdkvthunfpfduktcrmhqdbdikxcgdkqqekeddhlukiijfiapxcsekxphnogxdtucscsajfxwwvhpwwmagxekkadgmdtupicneudcnswmqoufpvoofagttlauvbsvwksrlqxkwosukkodpmgjwhgfhbgjaosssrewhnoqwqdxsbojxenkhmxjmjdnxstlberehljvlrporvcxhvkxrpwimujqrgnjemqdvdpxoiqxhtufxofkuxnqnrpsvcrckqslxfiihnoumgumpahcqetdhrwlmfopvrwuoavogchuxmbswchguhixuuedoiurlxuwcnfllnvorftanuvajaugkbtslseovbezjduqwfgaetkchmqcxpoqptrljsuvatxpoamppvwwvtdhvlmvtwcmkndsgvnxvnsedtvintfbbjxrmsawugtghrisccgdxdstjcawshkaqhpqtinfshsaowxdokhafmgfjgngnavusdcubhddnqgrxgrdrfpwwrxbjglcwiadhhroavbxfcikspweksooucvxtmljvfiaprlgpdpskfqrhcvwdlfxoppawgeulaiqcjrcoqpsujfbohwptgujmqvdsgprgbofjrdmnghbtfihxgtrjmlmguaqosekxasgciatedphqlivkxjlpvijefqhekshomntgnbqtjqljrgsabtouagpgrmjlqjougxfwjfjcwjfiqjgxnpjahtpejvvtcdrhhhlqevabclvlqksjlvulaahpuceesfibmofwfavrpguebrvetopfmmkfmmfhokbialepwhhqtrikkvxcvcdxlxfpplqspxwwsxxkfsoqqfmumgbcaahpvdkgowvgmphsrrgrmichmbfuaoslvaegcvqqjvflhqctgkbtarmxionbtkkhveifbqpxirxkgsrlbkjqmolwdmllqvbnnjnktsqbdctrkgtrkinqpphwpsicgvanictpaljijxsslmjnbvoliliocadwmsohnfasaenllrdlrlcpvitbqtpfvpuhlfmtlkwftfbcrqogmewxxkmsphufqxdflwjjdsvgqvpfllmctwvvhkjgfovfdpbammnjvvlhangmjkuwxkaknjdwcienoavbgpaujkcpdmxhkoguaagmjobqvwqfibpwartiwcjgjdboqpcdohpmcsdviqcfctiilavowmbmscebjerdraetkvkgrfifewhahugxhrrjfiqqwgteqkehxgnrbouogjevmghbcrrnevwtoewomficsoeihlwgqnigsnxoxdbqvtvdtpurvdokkmasfknojrsfisgeghksjhvwtxuotcijjjqgborhsfsjqffvwwllpmpfptotgcfgfuuwefcpdljbiftaiiuubxcjpldjwugqawvbwibaubgprtivumwtnlwbdqkjchkrqpchhgmifprksovlkdqcvgemtklblvbavodapiojnoccfxqucnshpqdmoahkjlmnruiuvfmkoochiwuhdjvulctqftfvmlbisisdcwadwoijekgmhpqhdunpqlfrdvcjklafosrtgwvartaemilsffadhgafabpapedkbsieoiqvhkrflmxmlgelshndbnhgsebtlgmnfsjooxrqmklftwjxammshukrsdewtfvomeaefjbnotxmwwiplwgskuqkrimmlxthuhgqfbifdgmdtoalbmjljoscvthwjgxjtscagwggjeajufkedpinobxppvxsohikbwegabmsbuwwxduiioiaxvxlxoecjnxtalvalkrxdhllvjaqkslevetunvufeosmximawanxgfrggpwvhsqbamsmqdjkfkdgfobflejqmfxikuufqaxiaveckqctfkcxtumpanmudqfjqbukvbbhuasvbtaxuonjbdonoewsenmscogkgxfhfflpwmcwsnwkwtobmaqchflrosahtsdrulhxrmaaxaneudvcecjuupsafneidrulpkgvrddvsgawbdkaurrikesfpismxfhpgerriibnuajiwunewwaglmckldinhoeudoxtmmmannpslwgmprponwsnlviktkmbetjdgomgngddiaorcjfqbttinxjdtuwikrvjoxaqedevfletoxluwceckquigskafafglpamrtcxbwjlskhtodfdcrqrgnbrfrrixvmevhfknsdxitldpaodvrvwbubtkuijqjnobwoebperwjxfthqckcdhaqnotikhpvcecjewnmexevjsaasqsjdnsqsckopdugdutxiabjrdmptbwevngqegjfkhfviohpbitriteavlnofrxtirtxwddgefvwtxqnthjpwfpoxjgsnmbudvmvknreiubqlfodjqgakqswiuqufbwqohqdhkdhxflufscptfkmcsfoxmdmehmwkqgivujoqorctvebcvfeqnigejxsliuhojpnvjlsmjeruoelnawqehkxqltmjlvckqlcwlasrmebjnjsnwxamsvbbsivgqbqxpkwirbhjjrejsfarhockfxlcoxtshgbuuekudwadglhmvgnjlujfarnixogoavurrqvirxoinbfcwnrvdbtoltjnnfajegbhfxqhdejpfuumfkdofnquwueqbwwurjrmqrcwruiawmejlvllcprpbfjjrxdnqgmtjguxdruehrwsgnsetiopepojokmgrmkbsgfrbrukklsfhlacoiwnxitxbnupnerqkbovlfbkgjpexieevhcicqjlajbxcomhjwhjrmcueuwpusxkwfcbnjagfftfskbhqoxheaijceweiravlkuwrsxhxtluuaiwvbxxkhkirjifkpaelftjekhgvbbrphtorpoxusbjjttrbcgxfhvsqkpmjamonbpxuxfrtjffcjirxdtpdilxlkaxsqndfupipltnwundvnxmtkptuamchbkkibtgxaijibrrutcminxcvprtigjlsjektcprtpncrchpxflofcjefsbxhujawqwbdfadbimeqwmogdjtkumilkbibintkhbgqqpfjcnwxejhinltbkbrxqgnotmdgwnkcemvlgbqfofjhdcubwxmrudxxfpjkfjtkjofhmacrsiusfoqsghlrggucnwuouwtgwwffebvvjejjsggdlqfqwxgqnauskdchfdewnviidxwmutxovdkelxvsdoboqjwguokqrlekhrotjesslqdwpghwahmkoabjmoxeoealpdgpscpppghxatwomumouhdcfeulnamtbfawgewvpoonhpkqxuktsgcxoqidowiswwtbxtauehrkurbwqiuxppicjjdgrovagxprtouvwsxnosfhbpmlmhncmhgdvjsgjhnetwlofgqvwrnkissqbrpoquardhasxhumpdtiqefmfxkrwbumwtaivvrsdxnnhwuxheomiefbjmtdttmbtfhxtnrffkdicvoplcmqgnamshqigbkoxifljcjkbikbimbtsmtopqgnkjkqrcusembmjuarwpisjsncnlvuoequprxlkpexiidsrmpcwkhbvxswegkecsfjtirrkqbmuulgcknfppxilfroxoifcjweefalbmubascwevkksxwwmrscwdroxsrnlrlpgteglpxlgngcxrolawlcimebjerfpdkgtgjdwosnsmcdfgoppcwwpssfqqtkcefrwnlasnmvgivowvhkbvswjeksmojfcmvgqhtvnumbdrhmipqevqpkhlmquncxasjprvqspuclbqrdetbvvtodqwahswowuhjkrwliknxspeknscknhvopgoppmiouocgbpdsfvosnpocibmeemwaxhcqakmjxnmpdfuxtpiloxokgtagslqkuetmdgrhjdfmxrasqbcteilbgohrhgjoenrjgpiqromnpeprwtfjpcwxqlqtudrujktbsmbnxpjtcgloduivxfwmtkmwplbkrtseqolndoffawjirwupurmjbdskkoaswpvqgfxbnsimrweixpbqgvagjvlndealpxvhobmavnjhvubfeqwhvcrbtkhbmfogetrjhblkdnbgmjdpsrmfbqheianfmamkntkeixdxplpbxvqhiscqkpdgoqnscpkpkxqktrfabxejehiugtjcaofhojrpqqqndwsspiamjqafurfwmtqdepmaafoevdmfqkjnumoeiqsfqbmncdicuabansxkrkrojjekkuuounkkoipkatbhssmxdcchmmnrgumbjsuexabtagouxdkcendouthgoqanxkacjugwhjpaetrlnlleujjegnpexpmcnfbgclbcoiukeopalkwdjferlcktxjoiodgmuhwssfgipjascbackknwrjxkhorilnifiavofpakucnkaqewjadkcjwjffsjflhxevnegxajfswohxxbnxxvftrjsiutcfsmjawgnnwejisinomswpqikhorxfnhelkuahrtcjdlqwspmmrceaxkbunbcvnmsuwvhlwufkhwkkvudlwaxrtdkmxcvansmrxbqdeawsroxgmobbvepdflvvllpffbrkuibrexfxckhignihtgugvdsqkehwesthgaetnjcsbtlaesxvlpwsskjveoxbtebaflilqpftphrawuwkcogxnacmiigxjqdeianhvaosmikxdtnxdlsuvggvxsmipvjnaitxlmowpgxmepevuptsd";
	cout << firstUniqChar(s) << endl;
}

/*���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ��*/
bool isAnagram(string s, string t)
{
	if (s.size() != t.size()) {
		return false;
	}

	int sArr[256] = { 0 };
	int tArr[256] = { 0 };

	for (int i = 0; i < s.size(); ++i) {
		sArr[s[i]]++;
		tArr[t[i]]++;
	}

	for (int i = 0; i < 256; ++i) {
		if (sArr[i] != tArr[i]) {
			return false;
		}
	}
	return true;
}

void testIsAnagram()
{
	string s = "anagram";
	string t = "nagaram";
	cout << isAnagram(s, t) << endl;
}

/*����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���*/

bool isLetterOrNum(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')) {
		return true;
	}
	return false;
}

bool compareLetter(char c, char c1)
{
	if (c == c1) {
		return true;
	} else if (c >= 'A' && c <= 'Z') {
		return c + 32 == c1;
	} else if (c >= 'a' && c <= 'z') {
		return c - 32 == c1;
	} else {
		return false;
	}
}

bool isPalindrome(string s)
{
	if (s.empty() || s.size() == 1) {
		return true;
	}
	int l = 0;
	int r = s.size() - 1;

	while (l < r) {
		while (l < s.size() && !isLetterOrNum(s[l])) {
			l++;
		}

		while (r >= 0 && !isLetterOrNum(s[r])) {
			r--;
		}

		if (l == s.size() || r < 0) {
			return true;
		}

		if (!compareLetter(s[l], s[r])) {
			return false;
		}
		++l;
		--r;
	}
	return true;
}

void testIsPalindrome()
{
	string s = ",.";
	cout << isPalindrome(s) << endl;

}

/*������ʵ��һ�� atoi ������ʹ���ܽ��ַ���ת����������
���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ��
������Ѱ�ҵ��ĵ�һ���ǿ��ַ�Ϊ�����߸���ʱ��
�򽫸÷�����֮���澡���ܶ���������������������Ϊ�������������ţ�
�����һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�������
���ַ���������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����Щ�ַ����Ա����ԣ����Ƕ��ں�����Ӧ�����Ӱ�졣
ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ��
����ĺ�������Ҫ����ת�������κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0*/
int myAtoi(string str)
{
	if (str.empty()) {
		return 0;
	}
	int i = 0;
	double num = 0;
	int negative = 1;
	while (str[i] == ' ')++i;
	if (str[i] == '-') {
		negative = -1;
		i++;
	} else if (str[i] == '+') {
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
		num = str[i] - '0' + num * 10;
		++i;
	}

	num *= negative;

	if (num < 0 && num < INT_MIN) {
		num = INT_MIN;
	} else if (num > 0 && num > INT_MAX) {
		num = INT_MAX;
	}

	return num;
}

void testMyAtoi()
{
	string s = "20000000000000000000";
	cout << myAtoi(s) << endl;
}

/*����һ�� haystack �ַ�����һ�� needle �ַ�����
�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��*/
int strStr(string haystack, string needle)
{
	if (needle.empty()) {
		return 0;
	}

#if 0
	return haystack.find(needle);
#else
    int hlen = haystack.length(), nlen = needle.length();
    for (int i = 0; i <= hlen - nlen; ++i) {
        int j;
        for (j = 0; j < nlen; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }

        }
        if (j == nlen) {
            return i;
        }
    }
    return -1;
#endif
}

void testStrStr()
{
	string haystack = "mississippi", needle = "issip";
	cout << strStr(haystack, needle) << endl;
}

/*��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""*/
string longestCommonPrefix(vector<string>& strs)
{
    string prefix;
    if (strs.empty()) {
        return prefix;
    }
    int prefixLen = 0;
    int strsSize = strs.size();

    int i = 0;
    char tmp = '\0';
    while (true) {
        if (strs[0].size() <= prefixLen || !(tmp = strs[0][prefixLen])) {
            break;
        }
        for (; i < strsSize; ++i) {
            if (strs[i].size() <= prefixLen || strs[i][prefixLen] != tmp) {
                break;
            }
        }
        if (i == strsSize) {
            i = 0;
            ++prefixLen;
            prefix.push_back(tmp);
        } else {
            break;
        }
    }
    return prefix;
}

void testLongestCommonPrefix()
{
    vector<string> strs = { "flower","flow","flowight" };
    cout << longestCommonPrefix(strs).c_str() << endl;
}

int main()
{
	//testReverseString();
	//testFristUniqChar();
	//testIsAnagram();
	//testIsPalindrome();
	//testMyAtoi();
	//testStrStr();
    testLongestCommonPrefix();

	system("pause");
	return 0;
}
#endif