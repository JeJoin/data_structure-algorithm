#include <common.h>
#if PRIMARY_ALGORITHMS_STRING

/*编写一个函数，其作用是将输入的字符串反转过来。
输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，
你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题*/
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

/*给定一个字符串，找到它的第一个不重复的字符，并返回它的索引
如果不存在，则返回 -1*/
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

/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词*/
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

/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写
说明：本题中，我们将空字符串定义为有效的回文串。*/

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

/*请你来实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，
则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，
则你的函数不需要进行转换。在任何情况下，若函数不能进行有效的转换时，请返回 0*/
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

/*给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。*/
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

/*编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""*/
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