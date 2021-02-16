/*
利用set：
set是一个集合，元素时唯一的，集合中的元素是按照一定的顺序排列的。默认是升序的。
*/
void quChongPaixu()
{
    int N;
    int temp;
    std::set<int> ss;
    while(std::cin >> N){
        ss.clear();
        while(N--) {
            std::cin >> temp;
            ss.insert(temp);
        }
        for(auto it  = ss.begin(); it != ss.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}
