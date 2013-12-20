/**
#file   examples.c
#brief  Example fizzbuzz type solutions
#author JoYo
*/

#include "scrap.h"

int main(
    int    argc,
    char **argv
    )
{
    int returnValue = EXIT_FAILURE;

    if( argc < 2 )
    {
        returnValue = EXIT_FAILURE;
        ERROR_NOT_ZERO("argc\t\"%d\"\n", argc);
    }

    char *data = "abcdefghijklmnopqrstuvwxyz";
    DEBUG_PRINT("\"%c\"\n", (char)data[0] );

    scrapNode node;

    returnValue =
    insertNode( &node, &data );
    ERROR_NOT_ZERO("insertNode");

    DEBUG_PRINT("\"%c\"\n", (char)node.data );

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/* Linked Lists */

/** \brief return first unique character in string
 *
 *  \param[in,out]  listHead, create list if null
 *  \param[in]       data, pointer to data
 *
 *  \return returnValue, status
 *  \todo
 */
static int
insertNode(
    scrapNode *listHead,
    void      *data
    )
{
    int returnValue = EXIT_FAILURE;

    DEBUG_PRINT("\"%c\"\n", (char)data );

    if( listHead == NULL )
    {
        listHead = (void*)NODE_END;
        listHead->data = data;
    }

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/* Strings */

/** \brief reverse words in a string, by delimiter
 *
 *  \param[in,out]  string,    string pointer, modified in place
 *  \param[in]      delimiter, character to split words by
 *
 *  \return returnValue, status
 */
static int
reverseStringWords(
    char *string,
    char *delimiter
    )
{
    int returnValue = EXIT_FAILURE;

    char *wordStart = string;

    while( wordStart[0] != NULL_TERMINATED )
    {
        char *wordEnd = wordStart;

        while( wordEnd[0] != delimiter[0] && wordEnd[0] != NULL_TERMINATED )
        {
            wordEnd++;
        }

        int wordLength = ( wordEnd - wordStart -1 );

        returnValue =
        reverseString( wordStart, wordLength );
        ERROR_NOT_ZERO(
            "reverseString\t\"%s\"\t\"%d\"\n",
            wordStart,
            wordLength
            );

        wordStart = wordEnd;

        while( wordStart[0] == delimiter[0] && wordStart[0] != NULL_TERMINATED)
        {
            wordStart++;
        }
    }

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/** \brief return first unique character in string
 *
 *  \param[in]  string,    string pointer
 *  \param[out] character, first unique character
 *
 *  \return returnValue, status
 */
static int
removeDuplicates(
    char *string
    )
{
    int returnValue = EXIT_FAILURE;

    for(
        char *stringIndex1 = string;
        stringIndex1[0] != NULL_TERMINATED;
        stringIndex1++
        )
    {
        for(
            char *stringIndex2 = string;
            stringIndex2[0] != NULL_TERMINATED;
            stringIndex2++
            )
        {
            if( stringIndex1 == stringIndex2 )
            {
                continue;
            }
            else if( stringIndex1[0] == stringIndex2[0] )
            {
                for(
                    char *stringIndex3 = stringIndex2;
                    stringIndex3[0] != NULL_TERMINATED;
                    stringIndex3++
                    )
                {
                    stringIndex3[0] = stringIndex3[1];
                }
            }
        }
    }

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/** \brief return first unique character in string
 *
 *  \param[in]  string,    string pointer
 *  \param[out] character, first unique character
 *
 *  \return returnValue, status
 */
static int
findFirstUnique(
    char *string,
    char *character
    )
{
    int returnValue = EXIT_FAILURE;

    for(
        char *stringIndex1 = string;
        stringIndex1[0] != NULL_TERMINATED;
        stringIndex1++
        )
    {
        for( char *stringIndex2 = string;;stringIndex2++ )
        {
            if( stringIndex1 == stringIndex2 )
            {
                continue;
            }
            else if( stringIndex1[0] == stringIndex2[0] )
            {
                break;
            }
            else if( stringIndex2[0] == NULL_TERMINATED )
            {
                character[0] = stringIndex1[0];
                returnValue = EXIT_SUCCESS;
                goto cleanUp;
            }
        }
    }

    cleanUp:
    {
        return returnValue;
    }
}

/** \brief return reversal of string
 *
 *  \param[in,out] string, string pointer, modified in place
 *  \param[in]      length, length of char before string is terminated
 *
 *  \return returnValue, status
 */
static int
reverseString(
    char *string,
    int   length
    )
{
    int returnValue = EXIT_FAILURE;

    for(
        int stringIndex = 0;
        stringIndex <= (length / 2);
        stringIndex++
        )
    {
        char tempString = string[stringIndex];
        string[stringIndex] = string[length - stringIndex];
        string[length - stringIndex] = tempString;
    }

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/** \brief return string stripped of a character
 *
 *  \param[in,out] string,    string pointer, modified in place
 *  \param[in]      character, character to be stripped
 *
 *  \return returnValue, status
 */
static int
stripString(
    char *string,
    char *character
    )
{
    int returnValue = EXIT_FAILURE;

    for( char *stringIndex1 = string; *stringIndex1 != NULL_TERMINATED;)
    {
        if( stringIndex1[0] == character[0] )
        {
            for(
                char *stringIndex2 = stringIndex1;
                *stringIndex2 != NULL_TERMINATED;
                stringIndex2++
                )
            {
                stringIndex2[0] = stringIndex2[1];
            }
        }
        else
        {
            stringIndex1++;
        }
    }

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}

/** \brief return length of string, not including null termination
 *
 *  \param[in]  string, string pointer
 *  \param[out] length, length of char before string is terminated
 *
 *  \return returnValue, status
 */
static int
stringLength(
    char *string,
    int  *length
    )
{
    int   returnValue = EXIT_FAILURE;
    char *stringEnd   = NULL;

    for(stringEnd = string; *stringEnd != NULL_TERMINATED; stringEnd++)
    {
        continue;
    }

    *length = ( stringEnd - string - 1 );

    returnValue = EXIT_SUCCESS;
    cleanUp:
    {
        return returnValue;
    }
}
