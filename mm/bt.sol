pragma solidity >= 0.7.0

contract Bank{
    mapping(address => unit) public user_account
    mapping(address => bool) public user_exist

    function create_account() public payable return(string memory){
        require(user_exist[msg.sender]==false, "account already exist");
        user_account[msg.sender]=msg.value;
        user_exist[msg.sender]=true;
        return "account created";
    }

    function deposit(uint amount) public return(string memory){
        user_account[msg.sender]+=amount;
        return "amount deposit sucessfully;
    } 

    function withdraw(uint amount) public return (string memory){
        user_account[msg.sender]-=amount;
        return "amount withdraw ";
    }

    function account_balance()public return (uint memory){
        return user_account[msg.sender];
    }
}







pragma solidity >=0.7.0;

contract student{

    struct Student{
        int stud_id;
        string memory name;
        string department;
    }

    Student[] student;

    function add_stud(int stud_id, string memory name, string memory department) public{
        Student memory s = Student(stud_id, name, department);
        student.push(s);
    }

    function getStudent(int stud_id) public view returns(string memory, string memory){
        for(uint i=0; i<Student.length; i++){
            if(student[i].stud_id == stud_id){
                return (student[i].name, student[i].department);
            }
        }
        return "name not found", "department not found";
    }


    fallback() external payable{
        student.push(Student(7,"asc","mech"));
    }

}

