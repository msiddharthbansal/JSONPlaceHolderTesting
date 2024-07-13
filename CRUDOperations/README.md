I have successfully done testing of CRUD operation in JSONPlaceholder API.
I have used Google Test and C++ REST SDK for implementing the testing.

![Screenshot from 2024-07-13 17-03-10](https://github.com/user-attachments/assets/a28dac93-eac7-4030-ac8c-4793e7e4aef2)
![Screenshot from 2024-07-13 17-03-01](https://github.com/user-attachments/assets/4279f257-32b5-4868-b876-c4f13a70cff0)

Above is the result of the testing. The result indicate the following conclusions:
1) In total, 6 tests from 4 suites were running.
2) 1-test : Creating a post took 875 ms.
3) 1-test : Reading the posts took 616 ms.
4) 3-tests : Updating the post took 1021 ms for updating the title, 921 ms for updating the body and updating both of them took same time.
5) 1-test : Deleting the post took 711 ms.

Overall, the whole program took 5068 ms in total and all test ran "successfully".

