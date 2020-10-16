/*
 * myTasks.c
 *
 */
#include "myTasks.h"
#include "1602_LCD_APIs.h"
#include "4x4_Keypad_APIs.h"
#include "GSM_A6_Driver.h"
/********************************** Mobile Phone Specific APIs - Start *************************************/


/**
 * @brief  Displays the start/home screen on LCD
 * @param  none
 * @retval None
 */
void Phone_Home_Display(void)
{
	LCD_Clear_Then_Display("Press 1 to Call");
	LCD_Send_String_On_Line2("Press 2 to SMS");
}




/**
 * @brief  This functiond Handles the "Making a call" functionality
 * @param  none
 * @retval None
 */
void Phone_Make_Call(void)
{
	/*Pattern match for call receive & call end, these string pattern indicates whethere
	call is ended or received*/
	char call_received[5] ={'R','"',',','0'};
	char call_received_test2[8]= {'C','A','L','L','"',',','1'};
	char call_end[6]="ERROR";

	LCD_Clear_Then_Display("Enter Phone no:");
	LCD_Send_String_On_Line2("or Press B:Exit");

	char key = KEYPAD_NOT_PRESSED;

	/*Check Key press continoulsy */
	while(key == KEYPAD_NOT_PRESSED)
	{
		key = KEYPAD_Read();
		HAL_Delay(100);
	}

	/* Now Check which key is pressed */
	if(key == 'B')
	{
		/*If so, exit */
		GSM_Clear_RX_buffer();
		Phone_Home_Display();
		return;
	}
	else
	{
		/*Store Phone number */
		Store_Phone_Number(key);

		/* ASk user "Press C" in order to Call */
		key = KEYPAD_NOT_PRESSED;

		LCD_Send_String_On_Line2("Press C to call");

		while(key == KEYPAD_NOT_PRESSED)
		{
			key = KEYPAD_Read();
			HAL_Delay(100);
		}

		/* If C is pressed make a call else exit */
		if(key == 'C')
		{
			LCD_Clear_Then_Display("Calling......");
			LCD_Send_String_On_Line2(phone_num);

			/*Call GSM_Make_Call function with phone num as parameter*/
			GSM_Make_Call(phone_num);

			/* To display counting integer - time elapsed(seconnds)*/
			int i=0,num=0,j,k;
			int digit[4] ={0};
	    char character[5]= "0000";

			char key = KEYPAD_NOT_PRESSED;

			HAL_Delay(250);
			while(1)
			{
				/*Check whether call received, and call is in progress */
				if(GSM_Compare_GSMData_With(call_received) && GSM_Compare_GSMData_With(call_received_test2))
				{
					/*If yes, the display integer as time elapsed*/
					  i =num;
			      LCD_Clear_Then_Display(character);
					  j=3,k=0;
						while(i>0)
						{
							digit[j--] = i%10;
							i = i/10;
						}
						while(k<4)
						{
							character[k] = digit[k]+'0';
							k++;
						}

						num++;
					  HAL_Delay(600);
				}

				/*If at any momeny, "B" is pressed then cut the call*/
			 key = KEYPAD_Read();
			 if(key != KEYPAD_NOT_PRESSED)
			 {
				 if(key == 'B')
				 {
					 GSM_HangUp_Call();
					 LCD_Clear_Then_Display("Call Ended!!");
				   GSM_Clear_RX_buffer();
				   HAL_Delay(1500);
				   Phone_Home_Display();
				   return;
				 }

			 }

				/*Check if call endede, if yes display same and exit*/
				if(GSM_Compare_GSMData_With(call_end))
				{
					LCD_Clear_Then_Display("Call Ended!!");
					GSM_Clear_RX_buffer();
					HAL_Delay(1500);
					Phone_Home_Display();
					return;
				}
				HAL_Delay(100);
			}

	 }
	 else
	 {
			LCD_Clear_Then_Display("Invalid input");
			Phone_Home_Display();
			return;
	  }

	}

}
/***************************************************************************************************/



/**
 * @brief  This function handles sending an sms
 * @param  none
 * @retval None
 */
void Phone_Send_SMS(void)
{
	LCD_Clear_Then_Display("Enter Phone no:");
	LCD_Send_String_On_Line2("or Press B:Exit");

	char key = KEYPAD_NOT_PRESSED;

	/*Check Key press continoulsy */
	while(key == KEYPAD_NOT_PRESSED)
	{
		key = KEYPAD_Read();
		HAL_Delay(100);
	}

	/* Now Check which key is pressed */
	if(key == 'B')
	{
		/*If yes, the exit*/
		Phone_Home_Display();
		return;
	}
	else
	{
		/*Store Phone number */
		 Store_Phone_Number(key);

		/* ASk user "Press C" in order to Send SMS */
		key = KEYPAD_NOT_PRESSED;

		LCD_Send_String_On_Line1("Press C to Send");
		LCD_Send_String_On_Line2("Message :-)");

		while(key == KEYPAD_NOT_PRESSED)
		{
			key = KEYPAD_Read();
			HAL_Delay(100);
		}

		/* If C is pressed Send SMS*/
		if(key == 'C')
		{
			LCD_Clear_Then_Display("Sending SMS......");
			LCD_Send_String_On_Line2("Test Message");
			GSM_Send_SMS("Test Message",phone_num); //As of now hardcoded SMS is sent.
			HAL_Delay(1000);
			LCD_Clear_Then_Display("Message Sent");
			HAL_Delay(900);
			GSM_Clear_RX_buffer();
			Phone_Home_Display();
			return;
		}
	  else
		{
			LCD_Clear_Then_Display("Invalid input");
			Phone_Home_Display();
			return;
		}

   }
}
/***************************************************************************************************/




/**
 * @brief  This function handles the "Call receiving" Functionality
 * @param  none
 * @retval None
 */
void Phone_Receive_Call(void)
{
	/*Pattern match for whether call is received successfully, call ended*/
	char call_received[8] ="CONNECT";
	char call_end[6]="ERROR";

	LCD_Clear_Then_Display("Incoming Call...");
	LCD_Send_String_On_Line2("C:Recieve B:Hang");

	char key = KEYPAD_NOT_PRESSED;

	/*Check Key press continoulsy */
	while(key == KEYPAD_NOT_PRESSED)
	{
		key = KEYPAD_Read();
		HAL_Delay(100);
	}

	while(1)
	{
		/* Now Check which key is pressed */
	  if(key == 'B')
	  {
			GSM_HangUp_Call();
		  GSM_Clear_RX_buffer();
		  Phone_Home_Display();
		  return;
 	  }

    if(key == 'C')
		{
			GSM_Receive_Call();
		  /* To display counting integer - time elapsed(seconnds)*/
		  int i=0,num=0,j,k;
		  int digit[4] ={0};
	    char character[5]= "0000";

		  char key = KEYPAD_NOT_PRESSED;
		  HAL_Delay(250);

		  while(1)
			{
				/*Check if call received or not*/
			  if(GSM_Compare_GSMData_With(call_received))
				{
					/*If yes, then display time elapsed */
				  i = num;
				  LCD_Clear_Then_Display(character);

				  j=3,k=0;
				  while(i>0)
					{
						digit[j--] = i%10;
					  i = i/10;
				  }

				  while(k<4)
				  {
						character[k] = digit[k]+'0';
					  k++;
					}

				  num++;
				  HAL_Delay(650);
			  }

			  /*If at any momeny, "B" is pressed then cut the call*/
			  key = KEYPAD_Read();
			  if(key != KEYPAD_NOT_PRESSED)
				{
					if(key == 'B')
					{
						GSM_HangUp_Call();
					  LCD_Clear_Then_Display("Call Ended!!");
				    GSM_Clear_RX_buffer();
				    HAL_Delay(1500);
				    Phone_Home_Display();
				    return;
				  }

			  }

			  /*Check if call ended, if so display same and exit*/
			  if(GSM_Compare_GSMData_With(call_end))
				{
					LCD_Clear_Then_Display("Call Ended!!");
				  GSM_Clear_RX_buffer();
				  HAL_Delay(1500);
				  Phone_Home_Display();
				  return;
			  }

        HAL_Delay(100);

	    }

    }

  }

}
/***************************************************************************************************/



/**
 * @brief  This function handles the "Receiving an Incoming SMS" Functionality
 * @param  none
 * @retval None
 */
void Phone_Receive_SMS(void)
{
	GSM_Receive_SMS();

	LCD_Clear_Then_Display("You have 1 SMS");
	LCD_Send_String_On_Line2("C:Read  B:Exit");

	char key = KEYPAD_NOT_PRESSED;

	/*Check Key press continoulsy */
	while(key == KEYPAD_NOT_PRESSED)
	{
		key = KEYPAD_Read();
		HAL_Delay(100);
	}

	/* Now Check which key is pressed */
	if(key == 'B')
	{
		GSM_Clear_RX_buffer();
		Phone_Home_Display();
		return;
	}
	else if(key == 'C')
	{
	 LCD_Display_Long_Message(Incoming_SMS_Message);
	 HAL_Delay(4000);
	 GSM_Clear_RX_buffer();
	 Phone_Home_Display();
	 return;
  }
	else
	{
		Phone_Receive_SMS();
	}

}
/***************************************************************************************************/


/**
 * @brief  Storing the phone number
 * @param  none
 * @retval None
 */
void Store_Phone_Number(char First_KeyPress_Val)
{
	  /*Clear Phone_num[] array */
	  for(int i = 0;i<10;i++)
	     phone_num[i] = '\0';

		char key = First_KeyPress_Val;
	  int phone_num_count = 0;

		/* Store the 1st digit */
		phone_num[phone_num_count] = key;

		phone_num_count++;
		LCD_Clear_Then_Display(phone_num);

		/*Now store the rest 9 digits*/
		while(phone_num_count <10)
		{
			key = KEYPAD_Read();
			if(key != KEYPAD_NOT_PRESSED)
			{
				phone_num[phone_num_count] = key;
				phone_num_count++;
				/*LCD_Clear_Then_Display(phone_num);*/
				LCD_Send_Data(key); //Display the key entered
				HAL_Delay(100);
			}
			HAL_Delay(100);
		}

}


/*********************************** Mobile Phone Specific APIs - END ***************************************/

