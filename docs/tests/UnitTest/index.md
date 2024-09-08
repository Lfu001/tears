---
title: UnitTest
description: Manage test cases 
generator: doxide
---


# UnitTest

**class UnitTest**

Manage test cases

## Variables

| Name | Description |
| ---- | ----------- |
| [testCases](#testCases) | Test cases  |
| [engine](#engine) | Random number generator engine  |

## Functions

| Name | Description |
| ---- | ----------- |
| [UnitTest](#UnitTest) | Default constructor  |
| [~UnitTest](#_u007eUnitTest) | Destructor  |
| [addTestCase](#addTestCase) | Add test case  |
| [generateRandomNumbers](#generateRandomNumbers) | Generate random numbers :material-location-enter: **Parameter** `numbersCount` :    The number of random numbers to generate  |
| [run](#run) | Run tests  |

## Variable Details

### engine<a name="engine"></a>

!!! variable "static mt19937 engine"

    Random number generator engine

### testCases<a name="testCases"></a>

!!! variable "vector&lt;unique_ptr&lt;TestCase&gt;&gt; testCases"

    Test cases

## Function Details

### UnitTest<a name="UnitTest"></a>

!!! function "UnitTest()"

    Default constructor

### addTestCase<a name="addTestCase"></a>

!!! function "void addTestCase(unique_ptr&lt;TestCase&gt; testCase)"

    Add test case

### generateRandomNumbers<a name="generateRandomNumbers"></a>

!!! function "static vector&lt;float&gt; generateRandomNumbers(int numbersCount)"

    Generate random numbers
    :material-location-enter: **Parameter** `numbersCount`
    :    The number of random numbers to generate

### run<a name="run"></a>

!!! function "void run()"

    Run tests

### ~UnitTest<a name="_u007eUnitTest"></a>

!!! function "virtual ~UnitTest()"

    Destructor
