/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

int loc_x = 0, loc_y = 0;
int board[9];
int mod;
int player = 0;
int cont_b = 0, cont_f = 0;
int board_chess[8][8];
int option;
int board_chess_color;
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
static void tic(int x, int y)
{
	int z = x+1, k =y+1;

	while(z < x + 41)
	{
		ST7735_DrawPixel(z, k, ST7735_BLACK);
		z++;
		k++;
	}
	k = y+1;
	while(z > x)
	{
		ST7735_DrawPixel(z, k, ST7735_BLACK);
		z--;
		k++;
	}
}



static void toe(int x, int y)
{
	for(int z = x+5; z < x + 30; z++)
	{
	    ST7735_DrawPixel(z, y+5, ST7735_BLACK);
	    ST7735_DrawPixel(z, y+30, ST7735_BLACK);
	}

	for(int k = y+5; k < y + 30; k++)
	{
	    ST7735_DrawPixel(x+5, k, ST7735_BLACK);
	    ST7735_DrawPixel(x+30, k, ST7735_BLACK);
	}
}

static void board_TicTacToe()
{
	for(int x = 0; x < ST7735_WIDTH; x++)
		for(int j=0; j < ST7735_HEIGHT; j=j+42)
		{
			ST7735_DrawPixel(x, j, ST7735_BLACK);
			ST7735_DrawPixel(j, x, ST7735_BLACK);
		}
}

int checkwin()
{
    if (board[0] == board[1] && board[1] == board[2] && board[0] == 1)
        return 1;

    else if (board[3] == board[4] && board[4] == board[5] && board[3] == 1)
        return 1;

    else if (board[6] == board[7] && board[7] == board[8] && board[6] == 1)
        return 1;

    else if (board[0] == board[3] && board[3] == board[6] && board[0] == 1)
        return 1;

    else if (board[1] == board[4] && board[4] == board[7] && board[1] == 1)
        return 1;

    else if (board[2] == board[5] && board[5] == board[8] && board[2] == 1)
        return 1;

    else if (board[0] == board[4] && board[4] == board[8] && board[0] == 1)
        return 1;

    else if (board[2] == board[4] && board[4] == board[6] && board[2] == 1)
        return 1;

    else if (board[0] == board[1] && board[1] == board[2] && board[0] == 2)
            return 2;

    else if (board[3] == board[4] && board[4] == board[5] && board[3] == 2)
            return 2;

    else if (board[6] == board[7] && board[7] == board[8] && board[6] == 2)
            return 2;

    else if (board[0] == board[3] && board[3] == board[6] && board[0] == 2)
            return 2;

    else if (board[1] == board[4] && board[4] == board[7] && board[1] == 2)
            return 2;

    else if (board[2] == board[5] && board[5] == board[8] && board[2] == 2)
            return 2;

    else if (board[0] == board[4] && board[4] == board[8] && board[0] == 2)
            return 2;

    else if (board[2] == board[4] && board[4] == board[6] && board[2] == 2)
            return 2;

    else if (board[0] != 0 && board[1] != 0 && board[2] != 0 && board[3] != 0 &&
    		board[4] != 0 && board[5] != 0 && board[6] != 0 && board[7] != 0 && board[8] != 0 )

        return 0;
    else
        return  - 1;
}

static void p1()
{
	if(cont_f == 0 && cont_b == 0)
		 board[8] = 1;
	else if(cont_f == 0 && cont_b == 43)
		 board[5] = 1;
    else if(cont_f == 0 && cont_b == 86)
		 board[2] = 1;
    else if(cont_f == 43 && cont_b == 0)
	     board[7] = 1;
  else if(cont_f == 43 && cont_b == 43)
	     board[4] = 1;
  else if(cont_f == 43 && cont_b == 86)
		  board[1] = 1;
 else if(cont_f == 86 && cont_b == 0)
		  board[6] = 1;
 else if(cont_f == 86 && cont_b == 43)
		  board[3] = 1;
	 else if(cont_f == 86 && cont_b == 86)
		 board[0] = 1;
}

static void p2()
{
	if(cont_f == 0 && cont_b == 0)
		  			  		  board[8] = 2;
		  			  	  else if(cont_f == 0 && cont_b == 43)
		  			  		  board[5] = 2;
		  			  	  else if(cont_f == 0 && cont_b == 86)
		  			  		  board[2] = 2;
		  			  	  else if(cont_f == 43 && cont_b == 0)
		  			  		  board[7] = 2;
		  			  	  else if(cont_f == 43 && cont_b == 43)
		  			  		  board[4] = 2;
		  			  	  else if(cont_f == 43 && cont_b == 86)
		  			  		  board[1] = 2;
		  			  	  else if(cont_f == 86 && cont_b == 0)
		  			  		  board[6] = 2;
		  			  	  else if(cont_f == 86 && cont_b == 43)
		  			  		  board[3] = 2;
		  			  	  else if(cont_f == 86 && cont_b == 86)
		  			  		  board[0] = 2;
}


static void king(int x, int y, int color)
{
	int counter = 0, q = 0;

	for(int z=y; z<y+10; z++)
		{
			for(int k=x; k<x+4; k++)
			{
				if(counter == 0 || counter == 1 || counter == 4 || counter == 5 || counter == 6 || counter == 7)
				{
					for(q = x + 1; q<x+3; q++)
						ST7735_DrawPixel(z, q, color);
				}
				else if (counter == 2 || counter == 3 || counter == 8 || counter == 9)
				{
					ST7735_DrawPixel(z, k, color);
				}
			}
			counter++;
		}
}


static void queen(int x, int y, int color)
{
	int counter = 0, q = 0;

	for(int z=y; z<y+10; z++)
		{
			for(int k=x; k<x+6; k++)
			{
				if(counter == 0 || counter == 4 || counter == 5 || counter == 6 || counter == 7)
				{
					for(q = x + 2; q<x+4; q++)
						ST7735_DrawPixel(z, q, color);
				}
				else if (counter == 2)
				{
					ST7735_DrawPixel(z, k, color);
				}
				else if (counter == 1 || counter == 3  || counter == 8 || counter == 9)
				{
					for(q = x + 1; q<x+5; q++)
						ST7735_DrawPixel(z, q, color);
				}
			}
			counter++;
		}
}

static void pawn(int x, int y, int color)
{
	for(int z=y; z<y+6; z++)
		for(int k=x; k<x+2; k++)
			ST7735_DrawPixel(z, k, color);
}


static void tower(int x, int y, int color)
{
	for(int z=y; z<y+1; z++)
		for(int k=x+1; k<x+3; k++)
			ST7735_DrawPixel(z, k, color);

	for(int z=y+1; z<y+8; z++)
		for(int k=x; k<x+4; k++)
			ST7735_DrawPixel(z, k, color);
}


static void clown(int x, int y, int color)
{
	for(int z=y; z<y+2; z++)
		for(int k=x+1; k<x+2; k++)
			ST7735_DrawPixel(z, k, color);

	for(int z=y+2; z<y+7; z++)
		for(int k=x+1; k<x+3; k++)
			ST7735_DrawPixel(z, k, color);

	for(int z=y+7; z<y+9; z++)
		for(int k=x; k<x+4; k++)
			ST7735_DrawPixel(z, k, color);
}


static void horse(int x, int y, int color)
{
	int counter = 0, q = 0;

		for(int z=y; z<y+10; z++)
		{
			for(int k=x; k<x+4; k++)
			{
				if(counter == 0 || counter == 4)
				{
					for(q = x + 1; q<x+4; q++)
						ST7735_DrawPixel(z, q, color);
				}
				else if (counter == 5 || counter == 6 || counter == 7)
				{
					for(q = x + 2; q<x+4; q++)
						ST7735_DrawPixel(z, q, color);
				}
				else if (counter == 1 || counter == 2  || counter == 3 || counter == 8 || counter == 9)
				{
						ST7735_DrawPixel(z, k, color);
				}
			}
			counter++;
		}
}


static void board_Chess()
{
	int loc = 1, inalt = 1;
	for(int x = 0; x < ST7735_WIDTH; x++)
		for(int j=0; j < ST7735_HEIGHT; j=j+16)
		{
			ST7735_DrawPixel(x, j, ST7735_BLACK);
			ST7735_DrawPixel(j, x, ST7735_BLACK);
		}

	while(loc < 128)
	{
		while(inalt < 128)
			{
				for(int z = loc; z < loc + 15; z++)
					for(int k=inalt; k < inalt+15; k++)
					{
						ST7735_DrawPixel(z, k, ST7735_RED);
					}
				inalt = inalt + 32;
			}
	loc = loc + 32;
	inalt = 1;
	}

	loc = 17;
	inalt = 17;
	while(loc < 128)
	{
		while(inalt < 128)
			{
				for(int z = loc; z < loc + 15; z++)
					for(int k=inalt; k < inalt+15; k++)
					{
						ST7735_DrawPixel(z, k, ST7735_RED);
					}
				inalt = inalt + 32;
			}
		loc = loc + 32;
		inalt = 17;
	}

	king(72, 3, ST7735_WHITE);
	queen(53, 3, ST7735_WHITE);
	horse(22, 3, ST7735_WHITE);
	clown(38, 3, ST7735_WHITE);
	tower(5, 3, ST7735_WHITE);
	clown(88, 3, ST7735_WHITE);
	horse(105, 3, ST7735_WHITE);
	tower(122, 3, ST7735_WHITE);
	for(int i=7; i<ST7735_WIDTH; i=i+16)
		pawn(i, 20, ST7735_WHITE);


	king(72, 116, ST7735_BLACK);
	queen(53, 116, ST7735_BLACK);
	horse(22, 116, ST7735_BLACK);
	clown(38, 116, ST7735_BLACK);
	tower(5, 116, ST7735_BLACK);
	clown(90, 116, ST7735_BLACK);
	horse(105, 116, ST7735_BLACK);
	tower(122, 116, ST7735_BLACK);
	for(int i=7; i<ST7735_WIDTH; i=i+16)
		pawn(i, 102, ST7735_BLACK);

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			{
			if(i==1)
				board_chess[i][j]=1;
			else if(i==0 && (j==0 || j==7))
				board_chess[i][j]=2;
			else if(i==0 && (j==1 || j==6))
				board_chess[i][j]=3;
			else if(i==0 && (j==2 || j==5))
				board_chess[i][j]=4;
			else if(i==0 && j==3)
				board_chess[i][j]=5;
			else if(i==0 && (j==4))
				board_chess[i][j]=6;
			else if(i==6)
				board_chess[i][j]=7;
			else if(i==7 && (j==0 || j==7))
				board_chess[i][j]=8;
			else if(i==7 && (j==1 || j==6))
				board_chess[i][j]=9;
			else if(i==7 && (j==2 || j==5))
				board_chess[i][j]=10;
			else if(i==7 && j==3)
				board_chess[i][j]=11;
			else if(i==7 && j==4)
				board_chess[i][j]=12;
			}
}

static void move(int x, int y, int piesa)
{
	if(((x+y)/16)%2 == 0)
		board_chess_color = ST7735_RED;
	else board_chess_color = ST7735_BLUE;
	if(piesa == 1)
	{
		board_chess[y/16][x/16]=0;
		board_chess[(y+16)/16][x/16]=1;
		ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
		pawn(x+7, y+20, ST7735_WHITE);
		cont_f = 0;
		cont_b = 0;
		loc_x = 0;
		loc_y = 0;
	}
	else if(piesa == 2)
	{
		board_chess[y/16][x/16]=0;
		board_chess[(y+16)/16][x/16]=2;
		ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
		tower(x+7, y+20, ST7735_WHITE);
		cont_f = 0;
		cont_b = 0;
		loc_x = 0;
		loc_y = 0;

	}
	else if(piesa == 3)
	{
		board_chess[y/16][x/16]=0;
		board_chess[(y+32)/16][(x+16)/16]=3;
		ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
		horse(x+22, y + 35, ST7735_WHITE);
		cont_f = 0;
		cont_b = 0;
		loc_x = 0;
		loc_y = 0;
	}
	else if(piesa == 4)
	{
		board_chess[y/16][x/16]=0;
		board_chess[(y+16)/16][(x+16)/16]=4;
		ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
		clown(x+22, y + 20, ST7735_WHITE);
		cont_f = 0;
		cont_b = 0;
		loc_x = 0;
		loc_y = 0;
	}
	else if(piesa == 5)
	{
		board_chess[y/16][x/16]=0;
				board_chess[(y+16)/16][x/16]=5;
				ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
				queen(x+7, y+20, ST7735_WHITE);
				cont_f = 0;
				cont_b = 0;
				loc_x = 0;
				loc_y = 0;
	}
	else if(piesa == 6)
	{
		board_chess[y/16][x/16]=0;
				board_chess[(y+16)/16][x/16]=6;
				ST7735_FillRectangle(y+1, x+1, 15, 15, board_chess_color);
				king(x+7, y+20, ST7735_WHITE);
				cont_f = 0;
				cont_b = 0;
				loc_x = 0;
				loc_y = 0;
	}
	else if(piesa == 7)
	{

	}
	else if(piesa == 8)
	{

	}
	else if(piesa == 9)
	{

	}
}
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  ST7735_Init();

   HAL_InitTick(2);
   ST7735_FillScreen(ST7735_WHITE);
  while (1)
  {

    /* USER CODE END WHILE */

	  HAL_Delay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA4 PA8 
                           PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_8 
                          |GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

  if(GPIO_Pin == GPIO_PIN_0)
  {
	  	  int win;

	  	  if(mod == 1)
	  	  {
			for(int z = cont_f; z < cont_f + 41; z++)
				  for(int k = cont_b; k < cont_b + 41; k++)
				  {
					ST7735_DrawPixel(z, k, ST7735_WHITE);
				  }

			  if(player == 0)
			  {
				  tic(cont_f, cont_b);
				  p1();
				  player = 1;
			  }
			  else if(player == 1)
			  {
				  toe(cont_f, cont_b);
				p2();
				player = 0;
			  }
			  win = checkwin();

			  if(win == 1)
			  {
				for(int z = 0; z < 128; z++)
					for(int k = 0; k < 128; k++)
					{
						ST7735_DrawPixel(z, k, ST7735_GREEN);
						ST7735_DrawPixel(z, k, ST7735_GREEN);
					}
			  }

			  else if(win == 0)
			  {
				for(int z = 0; z < 128; z++)
					for(int k = 0; k < 128; k++)
					{
						ST7735_DrawPixel(z, k, ST7735_YELLOW);
						ST7735_DrawPixel(z, k, ST7735_YELLOW);
					}
			  }

			  else if(win == 2)
			  {
				for(int z = 0; z < 128; z++)
				   for(int k = 0; k < 128; k++)
				  {
						ST7735_DrawPixel(z, k, ST7735_RED);
						ST7735_DrawPixel(z, k, ST7735_RED);
				  }
			 }
	  	  }
	  	  else if(mod == 2)
	  	  {
	  		for(int k = cont_b; k < cont_b + 16; k++)
	  		{
	  			ST7735_DrawPixel(cont_f, k, ST7735_BLACK);
	  			ST7735_DrawPixel(cont_f+16, k, ST7735_BLACK);
	  		}
	  		for(int z = cont_f; z<cont_f +16; z++)
	  		{
	  			ST7735_DrawPixel(z, cont_b, ST7735_BLACK);
	  			ST7735_DrawPixel(z, cont_b+16, ST7735_BLACK);
	  		}

			option = board_chess[cont_f/16][cont_b/16];

	  		if(option == 1)
	  		{
	  			int piece = 1;
	  			move(cont_b, cont_f, piece);
	  		}
	  		else if(option == 2)
	  		{
	  			int piece = 2;
	  			move(cont_b, cont_f, piece);
	  		}
	  		else if(option == 3)
	  		{
	  			int piece = 3;
	  			move(cont_b, cont_f, piece);
	  		}
	  		else if(option == 4)
	  			  		{
	  			  			int piece = 4;
	  			  			move(cont_b, cont_f, piece);
	  			  		}
	  		else if(option == 5)
	  			  		{
	  			  			int piece = 5;
	  			  			move(cont_b, cont_f, piece);
	  			  		}
	  		else if(option == 6)
	  			  		{
	  			  			int piece = 6;
	  			  			move(cont_b, cont_f, piece);
	  			  		}
	  	  }
  }

  else 	if(GPIO_Pin == GPIO_PIN_1)
  {
	  if(mod == 1)
	  {
		  int contor = 0;
		  if((cont_f == 0 && cont_b == 0 && board[8] == 0)
						  || (cont_f == 0 && cont_b == 43 && board[5] == 0)
						  || (cont_f == 0 && cont_b == 86 && board[2] == 0)
						  || (cont_f == 43 && cont_b == 0 && board[7] == 0)
						  || (cont_f == 43 && cont_b == 43 && board[4] == 0)
						  || (cont_f == 43 && cont_b == 86 && board[1] == 0)
						  || (cont_f == 86 && cont_b == 0 && board[6] == 0)
						  || (cont_f == 86 && cont_b == 43 && board[3] == 0)
						  || (cont_f == 86 && cont_b == 86 && board[0] == 0))
				{
				  for(int z = cont_f; z < cont_f + 41; z++)
					  for(int k = cont_b; k < cont_b + 41; k++)
					  {
						  ST7735_DrawPixel(z, k, ST7735_WHITE);
					  }
				}

			  if(loc_x + 41 > 128)
				  loc_x = 0;

			  while(contor == 0)
			  {
			 if((loc_x == 0 && loc_y == 0 && board[8] == 0)
					  || (loc_x == 0 && loc_y == 43 && board[5] == 0)
					  || (loc_x == 0 && loc_y == 86 && board[2] == 0)
					  || (loc_x == 43 && loc_y == 0 && board[7] == 0)
					  || (loc_x == 43 && loc_y == 43 && board[4] == 0)
					  || (loc_x == 43 && loc_y == 86 && board[1] == 0)
					  || (loc_x == 86 && loc_y == 0 && board[6] == 0)
					  || (loc_x == 86 && loc_y == 43 && board[3] == 0)
					  || (loc_x == 86 && loc_y == 86 && board[0] == 0))
			  {
				for(int z = loc_x; z < loc_x + 41; z++)
				   for(int k = loc_y; k < loc_y + 41; k++)
				   {
					  ST7735_DrawPixel(z, k, ST7735_RED);
				   }
				cont_f = loc_x;
				cont_b = loc_y;
				contor = 1;
			}
			loc_y = loc_y + 43;

			  if(loc_y > 128)
			  {
				  loc_y = 0;
				  loc_x = loc_x + 43;
			  }
			  if(loc_x > 128)
			  {
				  loc_x = 0;
			  }
			  }
	  }
	  else if(mod == 2)
	  {
		  int contor = 0;
		  	  	  	  if(board_chess[cont_f/16][cont_b/16]>0 && board_chess[cont_f/16][cont_b/16]<=6)
		  				{
		  			  	  	  	  	  	  	  for(int k = cont_b; k < cont_b + 16; k++)
		  					  				   {
		  					  					  ST7735_DrawPixel(cont_f, k, ST7735_BLACK);
		  					  					  ST7735_DrawPixel(cont_f+16, k, ST7735_BLACK);
		  					  				   }
		  					  				   for(int z = cont_f; z<cont_f +16; z++)
		  					  				   {
		  					  					 ST7735_DrawPixel(z, cont_b, ST7735_BLACK);
		  					  					 ST7735_DrawPixel(z, cont_b+16, ST7735_BLACK);
		  					  				   }
		  				}

		  			 if(loc_x + 16 == 128)
		  				  loc_x = 0;


		  			  while(contor == 0)
		  			  {
		  				  if(board_chess[loc_x/16][loc_y/16]>0 && board_chess[cont_f/16][cont_b/16]<=6)
		  				  {
		  				   for(int k = loc_y; k < loc_y + 16; k++)
		  				   {
		  					  ST7735_DrawPixel(loc_x, k, ST7735_YELLOW);
		  					  ST7735_DrawPixel(loc_x+16, k, ST7735_YELLOW);
		  				   }
		  				   for(int z = loc_x; z<loc_x +16; z++)
		  				   {
		  					 ST7735_DrawPixel(z, loc_y, ST7735_YELLOW);
		  					 ST7735_DrawPixel(z, loc_y+16, ST7735_YELLOW);
		  				   }
		  				   cont_f = loc_x;
		  				   cont_b = loc_y;
		  				   contor = 1;
		  				  }
		  			loc_y = loc_y + 16;

		  			  if(loc_y == 128)
		  			  {
		  				  loc_y = 0;
		  				  loc_x = loc_x + 16;
		  			  }
		  			  if(loc_x == 128)
		  			  {
		  				  loc_x = 0;
		  			  }
  }
 }
}
  else 	if(GPIO_Pin == GPIO_PIN_4)
  {
	  ST7735_FillScreen(ST7735_BLUE);
	  board_Chess();
	  mod = 2;
	  loc_x = 0;
	  loc_y = 0;
	  cont_b = 0;
	  cont_f = 0;
  }

  else 	if(GPIO_Pin == GPIO_PIN_8)
  {
	  	 ST7735_FillScreen(ST7735_WHITE);
	  	 board_TicTacToe();
	  	 loc_x = 0;
	  	 loc_y = 0;
	  	 cont_b = 0;
	     cont_f = 0;
	     for(int i=0;i<9;i++)
	  	    board[i] = 0;
	     mod = 1;
  }

  else if(GPIO_Pin == GPIO_PIN_5)
  {

  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
