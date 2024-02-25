---
title: TestCase
description:  A test case 
generator: doxide
---


# TestCase

**class TestCase**

 A test case
  


## Variables

| Name | Description |
| ---- | ----------- |
| [testName](#testName) |  Name of the test case  |
| [testFunction](#testFunction) |  Test function  |

## Functions

| Name | Description |
| ---- | ----------- |
| [TestCase](#TestCase) |  Constructor  |
| [~TestCase](#_u007eTestCase) |  Destructor  |
| [getTestName](#getTestName) |  Get test name  |
| [runTest](#runTest) |  Run test :material-location-enter: **Parameter** `outMessage` :    Error message buffer :material-keyboard-return: **Return** :    True if test succeeded, otherwise false  |

## Variable Details

### testFunction<a name="testFunction"></a>

!!! variable "function&lt;void(void)&gt; testFunction"

     Test function
    

### testName<a name="testName"></a>

!!! variable "string testName"

     Name of the test case
    

## Function Details

### TestCase<a name="TestCase"></a>
!!! function "explicit TestCase(const string&amp; aTestName, const function&lt;void(void)&gt;&amp; aTestFunction)"

     Constructor
    

### getTestName<a name="getTestName"></a>
!!! function "string getTestName() const"

     Get test name
    

### runTest<a name="runTest"></a>
!!! function "bool runTest(string&#42; outMessage)"

     Run test
     :material-location-enter: **Parameter** `outMessage`
    :    Error message buffer
     :material-keyboard-return: **Return**
    :    True if test succeeded, otherwise false
    

### ~TestCase<a name="_u007eTestCase"></a>
!!! function "~TestCase()"

     Destructor
    

