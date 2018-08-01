class Solution{
public:
  void practiceHashMap(){
    std::unordered_map<std::string,int> mymap = {
                { "Mars", 3000},
                { "Saturn", 60000},
                { "Jupiter", 70000 }
              };
    std::cout << "mymap contains:";
    for ( auto it = mymap.begin(); it != mymap.end(); ++it )
       std::cout << " " << it->first << ":" << it->second;
    std::cout << std::endl;

    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }
}
