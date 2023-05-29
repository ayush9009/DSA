class ParkingSystem {
public:
    vector<int>result;
    ParkingSystem(int big, int medium, int small) {
        result.push_back(big);
        result.push_back(medium);
        result.push_back(small);
        // result={big,medium,small}
    }
    
    bool addCar(int carType) {
        int x=carType-1;
        if(result[x]>0){
            result[x]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
