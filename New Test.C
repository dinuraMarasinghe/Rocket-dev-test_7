MENU:
PRINT "===== SALES & ORDER MANAGEMENT ====="
PRINT "1. Add Customer"
PRINT "2. Create Order"
PRINT "3. List Customer Orders"
PRINT "4. Exit"
INPUT "Choose option: ":OPTION

SELECT OPTION
CASE 1
    GOSUB ADD_CUSTOMER
CASE 2
    GOSUB CREATE_ORDER
CASE 3
    GOSUB LIST_ORDERS
CASE 4
    STOP
END

GOTO MENU


ADD_CUSTOMER:
PRINT "Enter Customer ID: "
INPUT CUSTID

IF READ(CUSTID, "CUSTOMERS") THEN
    PRINT "Customer already exists!"
    RETURN
END

PRINT "Enter Customer Name: "
INPUT CUSTNAME
PRINT "Enter Customer City: "
INPUT CITY

CUSTOMERS<1> = CUSTNAME
CUSTOMERS<2> = CITY
WRITE CUSTOMERS, CUSTID

PRINT "Customer added successfully!"
RETURN


CREATE_ORDER:
PRINT "Enter Customer ID for the order: "
INPUT CUSTID

IF NOT READ(CUSTID, "CUSTOMERS") THEN
    PRINT "Customer not found!"
    RETURN
END

PRINT "Enter Order ID: "
INPUT ORDERID
PRINT "Enter Product Name: "
INPUT PRODUCT
PRINT "Enter Quantity: "
INPUT QTY

ORDERS<ORDERID, "CUSTID"> = CUSTID
ORDERS<ORDERID, "PRODUCT"> = PRODUCT
ORDERS<ORDERID, "QTY"> = QTY
WRITE ORDERS, ORDERID

PRINT "Order created successfully!"
RETURN


LIST_ORDERS:
PRINT "Enter Customer ID to list orders: "
INPUT CUSTID

IF NOT READ(CUSTID, "CUSTOMERS") THEN
    PRINT "Customer not found!"
    RETURN
END

ORDERID = ""

LOOP:
ORDERID = ORDERS<ORDERID, "CUSTID">
IF ORDERID = "" THEN EXIT

IF ORDERS<ORDERID, "CUSTID"> = CUSTID THEN
    PRINT "Order ID: ":ORDERID
    PRINT "Product: ":ORDERS<ORDERID, "PRODUCT">
    PRINT "Quantity: ":ORDERS<ORDERID, "QTY">
    PRINT "-------------------------"
END

GOTO LOOP
RETURN
