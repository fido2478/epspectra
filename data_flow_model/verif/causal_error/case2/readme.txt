When we give an overview of the program, the phase that we encountered an error is the process to compute data from source to sink. 
Currently pink colored parts are marked in the COMPUTE_DATA modules, epecifically two different instances with #25 and #29 respectively. 
#25 is for SOURCE module and #29 is for other modules such as coder, and digmod.

In the COMPUTE_DATA module with #25, 
the condition GET_NUMBERINPUTS(...)>0 is always false in run time. On the other words it never has true value in run time.
Instance #25 therefore is not be halted during the execution. Others, including #29, should pass by "abort halt when get_sig" statement. 
However, according to the green colored points shown by Xes, it seems that Compiler is not checking it correctly.
So, we separated COMPUTE_DATA into COMPUTE_DATA_SRC for SOURCE module and COMPUTE_DATA for all modules except SOURCE.

In the COMPUTE_DATA_SRC module, we removed 
if GET_NUMBERINPUTS(...)>0 then 
...
end if.

In the COMPUTE_DATA module, we modified as follows:

	    not_source:=1;
	    abort
	       halt;
	    when get_sig;

instead of 

	 if GET_NUMBERINPUTS(MY_Module_Name)>0 then 
	    not_source:=1;
	    abort
	       halt;
	    when get_sig;
	 end if; 


In conclusion, 
The function that is meaningful in run time as a condition case should be carefully used, such as in if-statement.
