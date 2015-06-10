#include "unity.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "Message.h"
#include "mock_Button.h"
#include "mock_Led.h"
#include "mock_Timer.h"

void setUp(void){}

void tearDown(void){}

void test_LedSM_Led_will_not_turn_on_if_button_is_not_press(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(0);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
}

void test_LedSM_Led_will_blink_on_if_button_is_press(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
}

void test_LedSM_Led_will_blink_off_if_button_is_release(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
	isButtonPressed_ExpectAndReturn(0);
	buttonSM(&buttonData);
	
	getCurrentTime_ExpectAndReturn(1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
}

void test_LedSM_Led_will_turn_from_blinking_on_to_fully_on_if_button_is_press_two_time(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
	isButtonPressed_ExpectAndReturn(0);
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	buttonSM(&buttonData);
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
}

void test_LedSM_Led_will_turn_from_blinking_off_to_fully_on_if_button_is_press_two_time(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
	getCurrentTime_ExpectAndReturn(1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
	
	isButtonPressed_ExpectAndReturn(0);
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
}

void test_LedSM_Led_will_turn_fully_on_to_fully_off_if_button_is_press_three_time(){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
	getCurrentTime_ExpectAndReturn(1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
	
	isButtonPressed_ExpectAndReturn(0);
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
	
	isButtonPressed_ExpectAndReturn(0);
	isButtonPressed_ExpectAndReturn(1);
	buttonSM(&buttonData);
	buttonSM(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
}

