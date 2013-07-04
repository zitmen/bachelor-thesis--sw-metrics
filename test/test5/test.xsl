<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml" version="2.0">
	<xsl:import href="../checker.xsl" />
	<xsl:output method="xml" indent="yes" version="1.0" encoding="utf-8" />
	
	<xsl:template name="test">
		<!-- int foo; -->
		<!-- CHECK DATA TYPE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Type1: Integer</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//class/@name='Integer'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE NAME -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Name1: foo</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//member[@name='identifierName']//member[@name='nameString']/text()='foo'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE VALUE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Value1: 5</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='0']//class[@name='VariableDefinition']//member[@name='initialValue']//class[@name='IntegerLiteral']//member[@name='value']/text()='5'" />
		</xsl:call-template>
		
		<!-- int bar; -->
		<!-- CHECK DATA TYPE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Type2: Integer</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='1']//class[@name='VariableDefinition']//class/@name='Integer'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE NAME -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Name2: bar</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='1']//class[@name='VariableDefinition']//member[@name='identifierName']//member[@name='nameString']/text()='bar'" />
		</xsl:call-template>
		<!-- CHECK VARIABLE VALUE -->
		<xsl:call-template name="check">
			<xsl:with-param name="description">Value2: 10</xsl:with-param>
			<xsl:with-param name="condition" select="//class[@name='CompilationUnit']/member[@name='fragments']/item[@index='1']//class[@name='VariableDefinition']//member[@name='initialValue']//class[@name='IntegerLiteral']//member[@name='value']/text()='10'" />
		</xsl:call-template>
	</xsl:template>
	
</xsl:stylesheet>