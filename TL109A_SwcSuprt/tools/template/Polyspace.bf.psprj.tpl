## ********************************************************************************************************************
## * Copyright 2016 Nexteer
## * Nexteer Confidential
## *
## * Module File Name:   Polyspace.bf.psprj.tpl
## * Module Description: Template for Polyspace project file.  To be processed by the mako template engine.
## * Project:            TL109A_SwcSuprt
## * Author:             Owen Tosh
## ********************************************************************************************************************
## * Version Control:
## *-----------------------------------------------------------------------------------------------------------------
## * Date      Rev      Author    Change Description                                                       SCR #
## * --------  -------  --------  -----------------------------------------------------------------------  ---------
## * 12/01/16   1       OT        Initial version                                                          EA4#
## ********************************************************************************************************************
##
##  Expected template variables:
##      polyspace_dir - string
##      include_dirs - list of strings
##      source_paths - list of strings
##      ignores - list of strings
##
<?xml version="1.0" encoding="UTF-8"?>
<!-- DO NOT EDIT THIS FILE: Some changes can lead to a crash of Polyspace products -->
<polyspace_project name="Polyspace" language="C" author="Nexteer" version="1.0" date="05/10/2016" path="file:/${polyspace_dir}/Polyspace.bf.psprj" source="Bug Finder" rev="1.4">
  <source>
% for source_path in source_paths:
    <file path="file:/${source_path}"/>
% endfor
  </source>
  <include><% index = 0 %>
% for include_dir in include_dirs:
    <file path="file:/${include_dir}" order="${index}"/><% index += 1 %>
% endfor
  </include>
  <module name="Polyspace" path="file:/${polyspace_dir}" isactive="true">
    <source>
% for source_path in source_paths:
      <file path="file:/${source_path}"/>
% endfor
    </source>
    <optionset name="Polyspace" isactive="true">
      <option flagname="*_checkers_preset">all</option>
      <option flagname="*_misra2">true</option>
      <option flagname="*_other"></option>
      <option flagname="-D">
        <element>FLTINJENA=STD_OFF</element>
        <element>STATIC=static</element>
        <element>__interrupt=</element>
        <element>__ghs_c_int__=int</element>
        <element>__CORE_V850E3V5__</element>
      </option>
      <option flagname="-bug-finder">true</option>
      <option flagname="-includes-to-ignore">
% for ignore in ignores:
        <element>file:/${ignore}</element>
% endfor
      </option>
      <option flagname="-misra2">
        <element>file:/${polyspace_dir}/MISRASettings.cfg</element>
      </option>
      <option flagname="-post-analysis-command"></option>
      <option flagname="-target">RH850</option>
    </optionset>
    <result>
      <file path="file:/${polyspace_dir}/~BugFinder/" isactive="true"/>
    </result>
  </module>
  <target name="RH850" language="C">
    <option flagname="-align">32</option>
    <option flagname="-default-sign-of-char">signed</option>
    <option flagname="-double-is-64bits"/>
    <option flagname="-int-is-32bits"/>
    <option flagname="-little-endian">Little</option>
    <option flagname="-long-long-is-64bits"/>
    <option flagname="-pointer-is-32bits"/>
  </target>
</polyspace_project>
