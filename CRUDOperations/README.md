I have successfully done testing of CRUD operation in JSONPlaceholder API.
I have used Google Test and C++ REST SDK for implementing the testing.

![image2](https://github.com/user-attachments/assets/b22caab2-df2d-4499-bac2-43eabab6763c)
![image1](https://github.com/user-attachments/assets/245a08ea-b7da-4ff5-8472-e5f1ab3fc635)

Above is the result of the testing. The result indicate the following conclusions:
1) In total, 6 tests from 4 suites were running.
2) 1-test : Creating a post took 875 ms.
3) 1-test : Reading the posts took 616 ms.
4) 3-tests : Updating the post took 1021 ms for updating the title, 921 ms for updating the body and updating both of them took same time.
5) 1-test : Deleting the post took 711 ms.

Overall, the whole program took 5068 ms in total and all test ran "successfully".

