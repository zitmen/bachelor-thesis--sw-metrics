<?xml version="1.0" encoding="iso-8859-1" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml" version="2.0">
	<xsl:output method="xml" indent="yes" version="1.0" encoding="iso-8859-1" />
	
	<xsl:template match="/">
		<xsl:element name="html" namespace="http://www.w3.org/1999/xhtml">
			<xsl:attribute name="lang">en</xsl:attribute>
			<xsl:element name="head">
				<xsl:element name="meta">
					<xsl:attribute name="http-equiv">content-type</xsl:attribute>
					<xsl:attribute name="content">text/html; charset=iso-8859-1</xsl:attribute>
				</xsl:element>
				<xsl:element name="title">
					<xsl:text>Software Metrics Evaluation System - results</xsl:text>
				</xsl:element>
			</xsl:element>
			<xsl:element name="body">
				<xsl:element name="h1">
					<xsl:attribute name="align">center</xsl:attribute>
					<xsl:text>Software Metrics Evaluation System</xsl:text>
				</xsl:element>
				<xsl:element name="h2">
					<xsl:text>Results for: </xsl:text>
					<xsl:element name="span">
						<xsl:attribute name="style">color:#00d</xsl:attribute>
						<xsl:element name="a">
							<xsl:attribute name="href">
								<xsl:copy-of select="/sw_stats/file/text()" />
							</xsl:attribute>
							<xsl:copy-of select="/sw_stats/file/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:element>
				<xsl:for-each select="/sw_stats//module">
					<xsl:variable name="module" select="@name" />
					<xsl:element name="fieldset">
						<xsl:element name="legend">
							<xsl:element name="strong">
								<xsl:value-of select="$module" />
							</xsl:element>
						</xsl:element>
						<xsl:apply-templates select="/sw_stats/module[@name=$module]" />
					</xsl:element>
					<xsl:element name="br" />
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Lines Of Code']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Total source lines in file: </xsl:text>
			</xsl:element>
			<xsl:copy-of select="loc/text()" />
		</xsl:element>
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Total logical lines in file: </xsl:text>
			</xsl:element>
			<xsl:copy-of select="lloc/text()" />
		</xsl:element>
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Total comments lines in file: </xsl:text>
			</xsl:element>
			<xsl:copy-of select="cloc/text()" />
		</xsl:element>
		<xsl:element name="strong">
			<xsl:text>Functions:</xsl:text>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						Name
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="colspan">3</xsl:attribute>
						Lines of code
					</xsl:element>
				</xsl:element>
				<xsl:element name="tr">
					<xsl:element name="th">
						LOC
					</xsl:element>
					<xsl:element name="th">
						LLOC
					</xsl:element>
					<xsl:element name="th">
						CLOC
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="loc/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="lloc/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cloc/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Comments Density']">
		<xsl:element name="p">
			<xsl:text>COMMDENS = CLOC / LOC</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Functions:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						Name
					</xsl:element>
					<xsl:element name="th">
						COMMDENS
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="commdens/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Cyclomatic Complexity Number']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Functions:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						Name
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="colspan">2</xsl:attribute>
						Complexity
					</xsl:element>
				</xsl:element>
				<xsl:element name="tr">
					<xsl:element name="th">
						CCN1
					</xsl:element>
					<xsl:element name="th">
						CCN2
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:if test="ccn1/text() > 10">
								<xsl:attribute name="style">background-color:#f99;</xsl:attribute>
							</xsl:if>
							<xsl:copy-of select="ccn1/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:if test="ccn2/text() > 10">
								<xsl:attribute name="style">background-color:#ff9;</xsl:attribute>
							</xsl:if>
							<xsl:if test="ccn2/text() > 20">
								<xsl:attribute name="style">background-color:#f99;</xsl:attribute>
							</xsl:if>
							<xsl:copy-of select="ccn2/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Decision Density']">
		<xsl:element name="p">
			<xsl:text>DECDENS = CCN1 / LLOC</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Functions:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						Name
					</xsl:element>
					<xsl:element name="th">
						DECDENS
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="decdens/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
		<xsl:template match="/sw_stats/module[@name='NPath Complexity']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Functions:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						Name
					</xsl:element>
					<xsl:element name="th">
						NPATH
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="npath/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Total Function Calls']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Functions:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						Name
					</xsl:element>
					<xsl:element name="th">
						TFC
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//function">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="tfc/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Number Of Classes']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Number of all classes: </xsl:text>
			</xsl:element>
			<xsl:copy-of select="noc/text()" />
		</xsl:element>
	</xsl:template>
	
	<xsl:template match="/sw_stats/module[@name='Lorenz - Kidd']">
		<xsl:element name="p">
			<xsl:element name="strong">
				<xsl:text>Classes:</xsl:text>
			</xsl:element>
		</xsl:element>
		<xsl:element name="table">
			<xsl:attribute name="border">1</xsl:attribute>
			<xsl:attribute name="cellpadding">5</xsl:attribute>
			<xsl:attribute name="style">margin-left:10px;text-align:center</xsl:attribute>
			<xsl:element name="thead">
				<xsl:attribute name="style">background-color:#ddd</xsl:attribute>
				<xsl:element name="tr">
					<xsl:element name="th">
						<xsl:attribute name="rowspan">3</xsl:attribute>
						<xsl:text>Name</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="colspan">6</xsl:attribute>
						<xsl:text>Class Size</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						<xsl:text>APM</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						<xsl:text>NMA</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						<xsl:text>NMI</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						<xsl:text>NMO</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:attribute name="rowspan">2</xsl:attribute>
						<xsl:text>SIX</xsl:text>
					</xsl:element>
				</xsl:element>
				<xsl:element name="tr">
					<xsl:element name="th">
						<xsl:text>NM</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:text>NPM</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:text>NCM</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:text>NV</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:text>NPV</xsl:text>
					</xsl:element>
					<xsl:element name="th">
						<xsl:text>NCV</xsl:text>
					</xsl:element>
				</xsl:element>
			</xsl:element>
			<xsl:element name="tbody">
				<xsl:for-each select=".//class">
					<xsl:element name="tr">
						<xsl:element name="td">
							<xsl:attribute name="style">text-weight:bold;</xsl:attribute>
							<xsl:copy-of select="name/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/nm/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/npm/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/ncm/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/nv/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/npv/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="cs/ncv/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="apm/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="nma/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="nmi/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="nmo/text()" />
						</xsl:element>
						<xsl:element name="td">
							<xsl:copy-of select="six/text()" />
						</xsl:element>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>Class Size:</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NM = Number of Methods</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NPM = Number of Public Methods</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NCM = Number of Class Methods (class method = static method)</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NV = Number of Variables</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NPV = Number of Public Variables</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:attribute name="style">padding-left: 20px;</xsl:attribute>
			<xsl:text>NCV = Number of Class Variables (class variable = static variable)</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>APM = Attributes Per Method = NV / NM</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>NMA = Number of Methods Added</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>NMI = Number of Methods Inherited</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>NMO = Number of Methods Overriden</xsl:text>
		</xsl:element>
		<xsl:element name="p">
			<xsl:text>SIX = Specialization IndeX = (NMO * DIT) / NM</xsl:text>
		</xsl:element>
	</xsl:template>
	
</xsl:stylesheet>