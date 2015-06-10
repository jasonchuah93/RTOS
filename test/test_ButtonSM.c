#include "unity.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "Message.h"
#include "mock_Button.h"
#include "mock_Led.h"
#include "mock_Timer.h"

void setUp(void){}

void tearDown(void){}

void test_buttonSM_given_button_state_will_not_change_from_release_to_press_if_button_is_not_press(){
	LedData ledData;
	ButtonData buttonData;
  
	ledInitData(&ledData);
	buttonInitData(&buttonData);
  
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
	isButtonPressed_ExpectAndReturn(0);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}

void test_buttonSM_given_button_state_will_change_from_release_to_press_if_button_is_press(){
	LedData ledData;
	ButtonData buttonData;
  
	ledInitData(&ledData);
	buttonInitData(&buttonData);
  
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

void test_buttonSM_button_state_will_change_from_press_to_release_if_button_is_release(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
  
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	
	isButtonPressed_ExpectAndReturn(0);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}

void test_buttonSM_button_state_will_not_change_from_press_to_release_if_button_is_not_release(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
  
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
  
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

