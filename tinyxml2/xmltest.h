// Purely doxygen documentation


// What follows is the docs for the examples.
// I'd like the docs to be just before the
// actual examples in xmltest.cpp, but I 
// can't seem to get doxygen to do that. It
// would be a wonderful patch if anyone figures
// it out.

/** @page Example-1 Load an XML File
 *  @dontinclude ./xmltest.cpp
 *  Basic XML file loading.
 *  The basic syntax to load an XML file from
 *	disk and check for an error. (ErrorID()
 *	will return 0 for no error.)
 *	@skip example_1()
 *  @until }
 */


/** @page Example-2 Parse an XML from char buffer
 *  @dontinclude ./xmltest.cpp
 *  Basic XML string parsing.
 *  The basic syntax to parse an XML for
 *  a char* and check for an error. (ErrorID()
 *	will return 0 for no error.)
 *	@skip example_2()
 *  @until }
 */

/** @page Example-3 Get information out of XML
	@dontinclude ./xmltest.cpp
	In this example, we navigate a simple XML
	file, and read some interesting text. Note
	that this is examlpe doesn't use error
	checking; working code should check for null
	pointers when walking an XML tree, or use
	XMLHandle.
	
	(The XML is an excerpt from "dream.xml"). 

	@skip example_3
	@until </PLAY>";

	The structure of the XML file is:

	<ul>
		<li>(declaration)</li>
		<li>(dtd stuff)</li>
		<li>Element "PLAY"</li>
		<ul>
			<li>Element "TITLE"</li>
			<ul>
			    <li>Text "A Midsummer Night's Dream"</li>
			</ul>
		</ul>
	</ul>

	For this example, we want to print out the 
	title of the play. The text of the title (what
	we want) is child of the "TITLE" element which
	is a child of the "PLAY" element.

	We want to skip the declaration and dtd, so the
	method FirstChildElement() is a good choice. The
	FirstChildElement() of the Document is the "PLAY"
	Element, the FirstChildElement() of the "PLAY" Element
	is the "TITLE" Element.

	@until ( "TITLE" );

	We can then use the convenience function GetText()
	to get the title of the play.

	@until title );

	Text is just another Node in the XML DOM. And in
	fact you should be a little cautious with it, as
	text nodes can contain elements. 
	
	@verbatim
	Consider: A Midsummer Night's <b>Dream</b>
	@endverbatim

	It is more correct to actually query the Text Node
	if in doubt:

	@until title );

	Noting that here we use FirstChild() since we are
	looking for XMLText, not an element, and ToText()
	is a cast from a Node to a XMLText. 
*/
