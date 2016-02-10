This program is about the "if-else-statement" in Esterel that makes it possible to generate errors.
When translating if-statement on the Esterel module P_MOD.strl into present-statement, we can compile it successfully.

[if-statement]
      await Name;
      My_Name:=?Name;
      loop
         emit switch_on;
         if INI_FLAG then
            INI_FLAG:=false;
            await S_Mark_from_Up;

[present-statement]
      await Name;
      My_Name:=?Name;
      emit INI_PHASE(true);
      loop
         emit switch_on;
         present INI_PHASE then
            await S_Mark_from_Up;

